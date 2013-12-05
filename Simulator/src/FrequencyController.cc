/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "FrequencyController.h"

namespace ns3 {

	FrequencyController::FrequencyController()
	{

	}

	FrequencyController::~FrequencyController(){}

	

	void FrequencyController::doLoadBalancing(std::map<Ipv4Address, uint64_t> &mapNewFrequency)
	{
		uint64_t add;
		if (mapNewFrequency.size() == 0)
			return;
		while(getMapSum(mapNewFrequency) <= m_maxFrequency)
		{

			uint64_t dif = m_maxFrequency - getMapSum(mapNewFrequency);
			add = dif/mapNewFrequency.size();
			for (std::map<Ipv4Address, uint64_t>::iterator it=mapNewFrequency.begin(); it!=mapNewFrequency.end(); ++it)
			{
				it->second += add + 1;
			}
		}
		while(m_maxFrequency < getMapSum(mapNewFrequency))
		{
			for (std::map<Ipv4Address, uint64_t>::iterator it=mapNewFrequency.begin(); it!=mapNewFrequency.end(); ++it)
			{
				it->second -= 1;
			}
		}

	};

	uint64_t FrequencyController::getMapSum(std::map<Ipv4Address, uint64_t> &mapNewFrequency)
	{
		uint64_t sum = 0;

		for (std::map<Ipv4Address, uint64_t>::iterator it=mapNewFrequency.begin(); it!=mapNewFrequency.end(); ++it)
		{
			sum += it->second;
		}

		return sum;
	};
};


