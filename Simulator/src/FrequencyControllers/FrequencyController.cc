/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "FrequencyController.h"

namespace ns3 {
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


