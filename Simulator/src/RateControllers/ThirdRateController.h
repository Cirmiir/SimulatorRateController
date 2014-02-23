/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef THIRDRATECONTROLLER_H
#define	THIRDRATECONTROLLER_H

#include "RateController.h"

namespace ns3 {

    class ThirdRateController : public RateController {
        
    public:
        ThirdRateController(UserDatabase &userDB,RateDatabase &userRD) 
        :RateController(userDB, m_userRD)
        {
        } 
        ~ThirdRateController(){};
        
        void doLoadBalancing(std::map<Ipv4Address, uint64_t> &mapNewRates, uint64_t curEnodebSpeed);
        

    private:
        std::string getTarif(Ipv4Address address)
        {
            return m_userDB.getTarifForUser(address);
        };
            


    };
}

#endif	/* RATECONTROLLER_H */

