/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef SECONDATECONTROLLER_H
#define	SECONDATECONTROLLER_H

#include "RateController.h"

namespace ns3 {

    class SecondRateController : public RateController{
        
    public:
        SecondRateController(UserDatabase &userDB,RateDatabase &userRD) 
        :RateController(userDB, m_userRD)
        {
        } 
        ~SecondRateController(){};
        void doLoadBalancing(std::map<Ipv4Address, uint64_t> &mapNewRates, uint64_t curEnodebSpeed);
        static RateController* Create(UserDatabase &userDB,RateDatabase &userRD)
        {
			return new SecondRateController(userDB,userRD);
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

