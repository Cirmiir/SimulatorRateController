/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef RATECONTROLLER_H
#define	RATECONTROLLER_H



#include "ns3/ipv4-address.h"
#include <map>
#include "ns3/UserDatabase.h"
#include "RateDatabase.h"

namespace ns3 {

    class RateController {
        
    public:
        const static uint32_t RATE_GRANULARITY = 500000;

        RateController(UserDatabase &userDB,RateDatabase &userRD);

        virtual ~RateController();



        virtual void doLoadBalancing(std::map<Ipv4Address, uint64_t> &mapNewRates, uint64_t curEnodebSpeed) = 0;

        void setMaxEnodebSpeed(uint64_t value) {
             m_maxEnodebSpeed = value;
        }

        void setRateDB(ns3::RateDatabase *user) {
            m_userRD = (*user);
        }

        uint64_t getMaxEnodebSpeed() {
            return m_maxEnodebSpeed;
        }
        
        void setRates(uint64_t minBitrate, uint64_t midBitrate, uint64_t maxBitrate) {
            m_minBitrate = minBitrate;
            m_midBitrate = midBitrate;
            m_maxBitrate = maxBitrate;
        }
        
        uint64_t getMaxBitrate(void) {return m_maxBitrate;}



        uint64_t getMapSum(std::map<Ipv4Address, uint64_t> &mapRates);


    protected:
        
        UserDatabase m_userDB;   
        RateDatabase m_userRD; 

        uint64_t ceilRate(uint64_t val);
        uint64_t Min(uint64_t A,uint64_t B); 
        
        uint64_t m_previsionEnodebSpeed;
        uint64_t m_maxEnodebSpeed;
        uint64_t m_add;

        uint64_t m_midBitrate;
        uint64_t m_maxBitrate;
        uint64_t m_minBitrate;


    };
}

#endif	/* RATECONTROLLER_H */

