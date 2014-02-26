/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#include <map>
#include "ns3/ipv4-address.h"
#include "Rate.h"
#ifndef CLIENT_H
#define CLIENT_H
class Client
{
public:
	Client(uint64_t bitRate,ns3::Ipv4Address addres,ns3::UserTarif tarif,ns3::UserQuality quality);
	Client(uint64_t bitRate,ns3::Ipv4Address addres,const char* tarif,const char* quality);
	Client(uint64_t bitRate,const char* addres,const char* tarif,const char* quality);
	~Client();
	void printInfo();
	void setBitrate(uint64_t bitrate)
	{
		m_bitRate = bitrate;
	};
	void setMaxBitrate(uint64_t bitrate)
	{
		m_maxbitRate = bitrate;
	};
	void setStartTime(double start)
	{
		m_startTime = start;
	};
	double getStartTime()
	{
		return m_startTime;
	};
	uint64_t getMaxBitrate()
	{
		return m_maxbitRate;
	};
	uint64_t getBitrate()
	{
			return m_bitRate;
	};
	double getCondition()
	{
			return m_condition;
	};
	ns3::Ipv4Address getAddress()
	{
		return address;
	};
	ns3::UserTarif getTarif()
	{
		return m_tarif;
	};
	std::string getNameQuality()
	{
		return ns3::RateDatabase::getNameForTarif(m_quality);
    }
	ns3::UserQuality getQuality()
	{
		return m_quality;
	};
	std::string getNameTarif()
	{
		return ns3::UserDatabase::getNameForTarif(m_tarif);
	};

private:
	ns3::Ipv4Address address;
	uint64_t m_bitRate;
	uint64_t m_maxbitRate;
	double m_condition;
	double m_startTime;
	ns3::UserTarif m_tarif;
	ns3::UserQuality m_quality;
};
#endif


