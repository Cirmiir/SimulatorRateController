/* 
 * File:   UserDatabase.h
 * Author: simon
 *
 * Created on August 26, 2013, 8:07 PM
 */


#include "ns3/ipv4-address.h"
#include <map>
#include "RateDatabase.h"


namespace ns3 {
    RateDatabase::RateDatabase(){
    	m_mapUsers = new std::map<ns3::Ipv4Address, enum UserQuality>();
    }
    RateDatabase::~RateDatabase(){
    }

};


