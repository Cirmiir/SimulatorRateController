#include "Channel.h"
#include <stdio.h>

Channel::Channel(uint64_t maxEnbodedSpeed)
	:m_maxEnbodedSpeed(maxEnbodedSpeed)
	{
		m_mapSpeed = new std::map<ns3::Ipv4Address, uint64_t>();
	}
Channel::~Channel()
	{
		delete m_mapSpeed;
	}

uint64_t Channel::getMapSum(std::map<ns3::Ipv4Address, uint64_t> &mapRates)
{
	uint64_t sum = 0;

		for (std::map<ns3::Ipv4Address, uint64_t>::iterator it=mapRates.begin(); it!=mapRates.end(); ++it)
    			sum += it->second;
		return sum;
};

