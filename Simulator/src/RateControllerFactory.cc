/*
 * RateControllerFactory.cpp
 *
 *  Created on: 24 февр. 2014 г.
 *      Author: Саха
 */

#include "RateControllerFactory.h"
#include <string.h>

RateControllerFactory::RateControllerFactory() {

	m_map["First"] = &ns3::FirstRateController::Create;
	m_map["Second"] = &ns3::SecondRateController::Create;
	m_map["Third"] = &ns3::ThirdRateController::Create;

}

RateControllerFactory::~RateControllerFactory() {
	// TODO Auto-generated destructor stub
}

ns3::RateController* RateControllerFactory::CreateController(const char* Ratetype,ns3::UserDatabase &userDB,ns3::RateDatabase &userRD,uint64_t threshold)
{
	if ((threshold != 0) && (strcmp(Ratetype,"First")==0))
		return (new ns3::FirstRateController(userDB,userRD))->setThreshord(threshold);

	if((m_map.find(Ratetype)) == (m_map.end()))
		return 0;

	return m_map.find(Ratetype)->second(userDB,userRD);
}

