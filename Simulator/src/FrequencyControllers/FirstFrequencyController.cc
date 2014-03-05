/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "FirstFrequencyController.h"

namespace ns3 {

	FirstFrequencyController::FirstFrequencyController()
	{

	}

	FirstFrequencyController::~FirstFrequencyController(){}

	

	void FirstFrequencyController::doLoadBalancing(std::map<Ipv4Address, uint64_t> &mapNewFrequency)
	{
		uint64_t add;
		if (mapNewFrequency.size() == 0)
			return;

		while(getMapSum(mapNewFrequency) <= m_maxFrequency)
		{

			uint64_t dif = m_maxFrequency - getMapSum(mapNewFrequency);
			add = dif / mapNewFrequency.size();
			for (std::map<Ipv4Address, uint64_t>::iterator it=mapNewFrequency.begin(); it!=mapNewFrequency.end(); ++it)
			{
				it->second += add + 1;
			}
		}
		while(m_maxFrequency < getMapSum(mapNewFrequency))
		{

			uint64_t dif = (getMapSum(mapNewFrequency) - m_maxFrequency);
			uint64_t less = ((dif > mapNewFrequency.size()) ? dif : mapNewFrequency.size() )/ mapNewFrequency.size();
			for (std::map<Ipv4Address, uint64_t>::iterator it=mapNewFrequency.begin(); it!=mapNewFrequency.end(); ++it)
			{
				if(it->second == 0)
					continue;

				if(it->second > less)
					it->second -= less;
				else
					it->second -= 1;
			}

		}

	}


};


