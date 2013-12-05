/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "RateController.h"
#include "Rate.h"

namespace ns3 {
	RateController::RateController(UserDatabase &userDB,RateDatabase &userRD):m_userDB(userDB),m_userRD(userRD)
	{
		m_minBitrate = RATE_GRANULARITY*100;
		m_midBitrate = RATE_GRANULARITY*200;
		m_maxBitrate = RATE_GRANULARITY*300;
		m_previsionEnodebSpeed = RATE_GRANULARITY*6000;
		m_maxEnodebSpeed = RATE_GRANULARITY*60000;
		m_add = RATE_GRANULARITY*125;
	}

	RateController::~RateController(){	}

	uint64_t RateController::getMapSum(std::map<Ipv4Address, uint64_t> &mapRates)
	{
		uint64_t sum = 0;

		for (std::map<Ipv4Address, uint64_t>::iterator it=mapRates.begin(); it!=mapRates.end(); ++it)
    		sum += it->second;
		return sum;
	}




	
	uint64_t RateController::ceilRate(uint64_t val)
	{
		return val - val % 500000;
	}

	uint64_t RateController::Min(uint64_t A, uint64_t B)
	{
		if(A < B)
			return A;
		return B;
	}
};


