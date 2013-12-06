/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "Simulator.h"
#include <time.h>
#include "Rate.h"
uint64_t Simulator::MapSum(){
	uint64_t sum = 0;

	for (std::map<ns3::Ipv4Address, Client>::iterator it=m_clients->begin(); it!=m_clients->end(); ++it)
			sum += it->second.getBitrate();

	return sum;
}
Simulator::Simulator(uint32_t client, Channel &chan,double step,std::string file)
:m_channel(chan)
{
	
	stepTime = step;
	m_time = 0;
	files = new std::ofstream();
	std::string folder="graph/";
	files->open(folder.append(file).c_str());
    srand(time(NULL));
	prevTime = 0;
	frequency = new ns3::FrequencyController();
}
	


void Simulator::AddClient(Client client)
{
	std::ostringstream subnet;
	subnet<<m_A<<"."<<m_B<<"."<<m_C<<"."<<m_D;
    ns3::Ipv4Address address = ns3::Ipv4Address(subnet.str().c_str());
		(*m_clients).insert(std::pair<ns3::Ipv4Address,Client>(address,client));

};

void Simulator::setClients(std::map<ns3::Ipv4Address, Client> &clients)
{
	m_A = m_B = m_C = m_D =0;
	ns3::UserDatabase user;
	ns3::RateDatabase rates;		
	m_clients = &clients;
	for (std::map<ns3::Ipv4Address, Client>::iterator it=m_clients->begin(); it!=m_clients->end(); ++it)
	{
		(user).RegisterUser(it->first,it->second.getTarif());
		(rates).RegisterUser(it->first,it->second.getQuality());
	}
	rate = (new ns3::FirstRateController(user,rates))->setThreshord(10*RATE_GRANULARITY);

}

Simulator::~Simulator()
{
	files->close();
	delete rate;
	delete frequency;
}



void Simulator::Step(){
	int trans=0;
	for (std::map<ns3::Ipv4Address, Client>::iterator it=m_clients->begin(); it!=m_clients->end(); ++it)
	{
		if(m_time >= it->second.getStartTime())
		{
			m_channel.transmit(it->first, it->second.getBitrate());
			trans++;
		}
	}

	std::map<ns3::Ipv4Address, uint64_t> mapFrequency; 
	/*for (std::map<ns3::Ipv4Address, uint64_t>::iterator it=map->begin(); it!=map->end(); ++it)
			mapFrequency.insert(std::pair<ns3::Ipv4Address, uint64_t>(it->first,it->second/m_clients->find(it->first)-> second.getCondition()));

	frequency->doLoadBalancing(mapFrequency);
	uint64_t freq;
	for (std::map<ns3::Ipv4Address, uint64_t>::iterator it=mapFrequency.begin(); it!=mapFrequency.end(); ++it)
		freq = it->second;
	*files <<m_time<<"  "<<freq<<" "<<trans<<"\n";
	m_channel.transmits(0.1, 0);
	m_time += 0.01;*/
	int64_t drop = m_channel.transmits(m_time,0);
	/*if (drop!=-1)
		//while(MapSum() > m_channel.getEnbodedSpeed())
			for (std::map<ns3::Ipv4Address, Client>::iterator it=m_clients->begin(); it!=m_clients->end(); ++it)
			{

				uint64_t cur_Bitrate = it->second.getBitrate();
				std::cout<< cur_Bitrate <<" " << drop <<"\n";
				if (cur_Bitrate > drop)
				{
					it->second.setBitrate(drop);
					std::cout<< drop/RATE_GRANULARITY <<"\n";
				}				
			}*/

	std::map<ns3::Ipv4Address, uint64_t>* map = m_channel.getSpeeds();
	if (m_time - prevTime > stepTime)
	{
		rate->doLoadBalancing(*map, 5*RATE_GRANULARITY);
		for (std::map<ns3::Ipv4Address, uint64_t>::iterator it=map->begin(); it!=map->end(); ++it)
		{
    			m_clients->find(it->first)-> second.setBitrate(it->second);
    	}
    	prevTime = m_time;
	}
	for (std::map<ns3::Ipv4Address, uint64_t>::iterator it=map->begin(); it!=map->end(); ++it)
			mapFrequency.insert(std::pair<ns3::Ipv4Address, uint64_t>(it->first,it->second/m_clients->find(it->first)-> second.getCondition()));

	
	std::cout << "In time " << m_time<<"s  ================\n";
	for (std::map<ns3::Ipv4Address, Client>::iterator it=m_clients->begin(); it!=m_clients->end(); ++it)
		{
			std::cout << "Bitrate for client "<<it->first<<"  "<< it->second.getNameTarif()<<"  " << it->second.getNameQuality()<<" "<< it->second.getBitrate()/RATE_GRANULARITY <<"Kb " << "\n";
		} 
	m_channel.EndTransmit();
	uint64_t sum=0;
	*files <<m_time<<"  ";
	for (std::map<ns3::Ipv4Address, Client>::iterator it=m_clients->begin(); it!=m_clients->end(); ++it)
	{
			sum += it->second.getBitrate();
	}
		
	*files << m_channel.getEnbodedSpeed() <<" " << sum <<" ";
	for (std::map<ns3::Ipv4Address, Client>::iterator it=m_clients->begin(); it!=m_clients->end(); ++it)
	{
			*files << it->second.getBitrate() <<" "<< it->second.getMaxBitrate()<<" ";
	}
	*files <<"\n";
	m_time +=0.01;

}

void Simulator::Run(double finish)
{
	while (m_time < finish)
		Step();
};

