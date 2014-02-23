/*
 * UsuallyChannel.cpp
 *
 *  Created on: 06 дек. 2013 г.
 *      Author: Саха
 */

#include "UsuallyChannel.h"
UsuallyChannel::~UsuallyChannel() {
}

void UsuallyChannel::transmit(ns3::Ipv4Address address, uint64_t speed)
{
	m_mapSpeed->insert(std::pair<ns3::Ipv4Address, uint64_t>(address,speed));
}

int64_t UsuallyChannel::transmits(double time,uint64_t add)
{
	setEnbodedSpeed((1*cos(3.1415926*2*time) + 1)*50000000*5*5);
	int64_t res = (int64_t(m_maxEnbodedSpeed)/(m_mapSpeed->size()));


	for (std::map<ns3::Ipv4Address, uint64_t>::iterator it=m_mapSpeed->begin(); it!=m_mapSpeed->end(); ++it)
	    if ((it->second > res)||(it->second == 0))
	    	it ->second= res;

	return res;
}

uint64_t UsuallyChannel::EndTransmit()
{
	delete m_mapSpeed;
	m_mapSpeed = new std::map<ns3::Ipv4Address, uint64_t>();
	return 0;
}

