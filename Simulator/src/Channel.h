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
	~Channel();
	void setEnbodedSpeed(uint64_t maxEnbodedSpeed);
	uint64_t getEnbodedSpeed()
	{
		return m_maxEnbodedSpeed;
	};
	void transmit(ns3::Ipv4Address address, uint64_t speed);
	int64_t transmits(double time,uint64_t add);
	std::map<ns3::Ipv4Address, uint64_t>* getSpeeds()
	{
		return m_mapSpeed;
	};
	void setSpeeds(std::map<ns3::Ipv4Address, uint64_t> map)
	{
	};
	uint64_t EndTransmit();
private:
	uint64_t getMapSum(std::map<ns3::Ipv4Address, uint64_t> &mapRates);
	uint64_t m_maxEnbodedSpeed;
	std::map<ns3::Ipv4Address, uint64_t> *m_mapSpeed;
};
#endif

