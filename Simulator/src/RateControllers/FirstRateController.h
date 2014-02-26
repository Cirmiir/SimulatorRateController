/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef FIRSTRATECONTROLLER_H
#define	FIRSTRATECONTROLLER_H

#include "RateController.h"

namespace ns3 {

    class FirstRateController : public RateController {
        
    public:
        FirstRateController(UserDatabase &userDB,RateDatabase &userRD) 
        :RateController(userDB, userRD)
        {
            m_minBitrate = RATE_GRANULARITY*10;
            m_midBitrate = RATE_GRANULARITY*15;
            m_maxBitrate = RATE_GRANULARITY*20;
            m_previsionEnodebSpeed = RATE_GRANULARITY*6000;
            m_maxEnodebSpeed = RATE_GRANULARITY*60000;
            m_add = RATE_GRANULARITY*125;
            m_threshold = 10;
        } 
        ~FirstRateController(){};
        FirstRateController* setThreshord(uint64_t threshold)
        {
            m_threshold = threshold;
            return this;
        };
        void doLoadBalancing(std::map<Ipv4Address, uint64_t> &mapNewRates, uint64_t curEnodebSpeed);
        static RateController* Create(UserDatabase &userDB,RateDatabase &userRD){
    		return new FirstRateController(userDB,userRD);
    	};
        

    private:
        std::string getTarif(Ipv4Address address)
        {
            return m_userDB.getTarifForUser(address);
        };
            
        uint64_t m_threshold;


    };
}

#endif	/* RATECONTROLLER_H */

