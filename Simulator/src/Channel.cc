#include "Channel.h"
#include <stdio.h>

	uint64_t ceilRate(uint64_t val)
	{
		return val - val % 500000; 
	}
Channel::Channel(uint64_t maxEnbodedSpeed){
	m_maxEnbodedSpeed = maxEnbodedSpeed;
	m_mapSpeed = new std::map<ns3::Ipv4Address, uint64_t>();
};

Channel::~Channel(){
};


void Channel::setEnbodedSpeed(uint64_t maxEnbodedSpeed){
	m_maxEnbodedSpeed = maxEnbodedSpeed;
};

void Channel::transmit(ns3::Ipv4Address address, uint64_t speed){
	m_mapSpeed->insert(std::pair<ns3::Ipv4Address, uint64_t>(address,speed));
};


int64_t Channel::transmits(double time,uint64_t add){
	setEnbodedSpeed((1*cos(3.1415926*2*time) + 1)*50000000*5*5);
	int64_t res = (int64_t(m_maxEnbodedSpeed)/(m_mapSpeed->size()));


	for (std::map<ns3::Ipv4Address, uint64_t>::iterator it=m_mapSpeed->begin(); it!=m_mapSpeed->end(); ++it)
    	if ((it->second > res)||(it->second == 0))
    		it ->second= res;

	return res;
};

uint64_t Channel::EndTransmit()
{
	delete m_mapSpeed;
	m_mapSpeed = new std::map<ns3::Ipv4Address, uint64_t>();
	return 0;
}
uint64_t Channel::getMapSum(std::map<ns3::Ipv4Address, uint64_t> &mapRates)
{
	uint64_t sum = 0;

		for (std::map<ns3::Ipv4Address, uint64_t>::iterator it=mapRates.begin(); it!=mapRates.end(); ++it)
    			sum += it->second;
		return sum;
};

