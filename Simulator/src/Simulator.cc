/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "Simulator.h"
#include <time.h>
#include "Rate.h"
#include "RateControllerFactory.h"
#include "FrequencyControllerFactory.h"

uint64_t Simulator::MapSum(){
	uint64_t sum = 0;

	for (std::map<ns3::Ipv4Address, Client>::iterator it=m_clients->begin(); it!=m_clients->end(); ++it)
			sum += it->second.getBitrate();

	return sum;
}
Simulator::Simulator(uint32_t client, Channel &chan,double step,std::string file,const char* frequencyController)
:m_channel(chan)
{
	stepTime = step;
	m_time = 0;
	m_files = new std::ofstream();
	std::string folder="graph/";
	m_files->open(folder.append(file).c_str());
    srand(time(NULL));
	m_prevTime = 0;
	m_frequency = FrequencyControllerFactory().createController(frequencyController);
	m_rate = 0;
	m_clients = 0;
}
	


void Simulator::AddClient(Client client)
{
	std::ostringstream subnet;
    ns3::Ipv4Address address = ns3::Ipv4Address(subnet.str().c_str());
		(*m_clients).insert(std::pair<ns3::Ipv4Address,Client>(address,client));

};

void Simulator::setClients(ClientList &clients,const char* RateController)
{
	ns3::UserDatabase user;
	ns3::RateDatabase rates;		
	m_clients = &clients;
	for (ClientList::iterator it=m_clients->begin(); it!=m_clients->end(); ++it)
	{
		(user).RegisterUser(it->first,it->second.getTarif());
		(rates).RegisterUser(it->first,it->second.getQuality());
	}
	RateControllerFactory* RCF = new RateControllerFactory();
	m_rate = RCF->CreateController(RateController,user,rates,10*RATE_GRANULARITY);

}

Simulator::~Simulator()
{
	m_files->close();
	delete m_rate;
	delete m_frequency;
}



void Simulator::Step(){
	int trans=0;
	for (ClientList::iterator it=m_clients->begin(); it!=m_clients->end(); ++it)
	{
		if(m_time >= it->second.getStartTime())
		{
			m_channel.transmit(it->first, it->second.getBitrate());
			trans++;
		}
	}

	std::map<ns3::Ipv4Address, uint64_t> mapFrequency; 
	/*
	m_channel.transmits(0.1, 0);
	m_time += 0.01;*/
	int64_t drop = m_channel.transmits(m_time,0);
	/*if (drop!=0)
		while(MapSum() > m_channel.getEnbodedSpeed())
			for (std::map<ns3::Ipv4Address, Client>::iterator it=m_clients->begin(); it!=m_clients->end(); ++it)
			{
				uint64_t cur_Bitrate = it->second.getBitrate();
				if (cur_Bitrate > drop)
				{
					it->second.setBitrate(drop);
					std::cout<< drop/RATE_GRANULARITY <<"\n";
				}				
			}*/

	std::map<ns3::Ipv4Address, uint64_t>* map = m_channel.getSpeeds();
	if (m_time - m_prevTime > stepTime)
	{
		m_rate->doLoadBalancing(*map, 5*RATE_GRANULARITY);
		for (std::map<ns3::Ipv4Address, uint64_t>::iterator it=map->begin(); it!=map->end(); ++it)
		{
    			m_clients->find(it->first)-> second.setBitrate(it->second);
    	}
    	m_prevTime = m_time;
	}
	for (std::map<ns3::Ipv4Address, uint64_t>::iterator it=map->begin(); it!=map->end(); ++it)
			mapFrequency.insert(std::pair<ns3::Ipv4Address, uint64_t>(it->first,it->second/m_clients->find(it->first)-> second.getCondition()));

	
	std::cout << "In time " << m_time<<"s  ================\n";
	for (ClientList::iterator it=m_clients->begin(); it!=m_clients->end(); ++it)
			it->second.printInfo();

	for (std::map<ns3::Ipv4Address, uint64_t>::iterator it=map->begin(); it!=map->end(); ++it)
				mapFrequency.insert(std::pair<ns3::Ipv4Address, uint64_t>(it->first,it->second/m_clients->find(it->first)-> second.getCondition()));

	//m_frequency->doLoadBalancing(mapFrequency);
	uint64_t freq;
	//for (std::map<ns3::Ipv4Address, uint64_t>::iterator it=mapFrequency.begin(); it!=mapFrequency.end(); ++it)
	//	freq = it->second;

	*m_files <<m_time<<"  "<<freq<<" "<<trans<<"\n";
	drop = m_channel.EndTransmit();
	uint64_t sum=0;
	*m_files <<m_time<<"  ";

	for (ClientList::iterator it=m_clients->begin(); it!=m_clients->end(); ++it)
			sum += it->second.getBitrate();
		
	*m_files << m_channel.getEnbodedSpeed() <<" " << sum <<" ";
	for (ClientList::iterator it=m_clients->begin(); it!=m_clients->end(); ++it)
			*m_files << it->second.getBitrate() <<" "<< it->second.getMaxBitrate()<<" ";

	*m_files <<"\n";
	m_time +=0.01;

}

void Simulator::Run(double finish)
{
	if (m_rate == 0)
	{
		std::cout << "RateController is not exist";
		return;
	}
	if (m_frequency == 0)
	{
		std::cout << "FrequencyController is not exist";
		return;
	}
	while (m_time < finish)
		Step();
};

