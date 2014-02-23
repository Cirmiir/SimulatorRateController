/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef CHANNEL_H
#define CHANNEL_H
#include "math.h"
#include <map>
#include "ns3/ipv4-address.h"


class Channel
{
public:

	Channel(uint64_t maxEnbodedSpeed);

	virtual ~Channel();

	virtual void transmit(ns3::Ipv4Address address, uint64_t speed) = 0;
	virtual int64_t transmits(double time,uint64_t add) = 0 ;
	virtual uint64_t EndTransmit() = 0;


	void setEnbodedSpeed(uint64_t maxEnbodedSpeed)
	{
		m_maxEnbodedSpeed = maxEnbodedSpeed;
	};
	std::map<ns3::Ipv4Address, uint64_t>* getSpeeds()
	{
		return m_mapSpeed;
	};

	uint64_t getEnbodedSpeed()
	{
		return m_maxEnbodedSpeed;
	};




protected:

	uint64_t getMapSum(std::map<ns3::Ipv4Address, uint64_t> &mapRates);
	uint64_t m_maxEnbodedSpeed;
	std::map<ns3::Ipv4Address, uint64_t> *m_mapSpeed;
};
#endif

