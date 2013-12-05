/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef FREQUENCYCONTROLLER_H
#define	FREQUENCYCONTROLLER_H



#include "ns3/ipv4-address.h"
#include <map>

namespace ns3 {

    class FrequencyController {
        
    public:
        
        FrequencyController();

        virtual ~FrequencyController();

        void setMaxFrequency(uint64_t value) {
            m_maxFrequency = value;
        }
         uint64_t getMaxFrequency() {
            return m_maxFrequency;
        }

        void doLoadBalancing(std::map<Ipv4Address, uint64_t> &mapNewFrequency);      

    private:
        uint64_t m_maxFrequency;
        uint64_t getMapSum(std::map<Ipv4Address, uint64_t> &mapNewFrequency);

    };
}

#endif	/* RATECONTROLLER_H */

