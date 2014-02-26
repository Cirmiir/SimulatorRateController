/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef FIRSTFREQUENCYCONTROLLER_H
#define	FIRSTFREQUENCYCONTROLLER_H



#include "FrequencyController.h"

namespace ns3 {

    class FirstFrequencyController : public FrequencyController{
        
    public:
        
    	FirstFrequencyController();

        virtual ~FirstFrequencyController();

        void doLoadBalancing(std::map<Ipv4Address, uint64_t> &mapNewFrequency);

        static FrequencyController* create()
        	{
        		return new FirstFrequencyController();
        	}

    };
}

#endif	/* RATECONTROLLER_H */

