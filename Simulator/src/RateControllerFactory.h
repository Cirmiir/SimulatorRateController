/*
 * RateControllerFactory.h
 *
 *  Created on: 24 февр. 2014 г.
 *      Author: Саха
 */

#ifndef RATECONTROLLERFACTORY_H_
#define RATECONTROLLERFACTORY_H_

#include "RateControllers/RateController.h"
#include "RateControllers/FirstRateController.h"
#include "RateControllers/SecondRateController.h"
#include "RateControllers/ThirdRateController.h"

class RateControllerFactory {
public:
	RateControllerFactory();
	ns3::RateController* CreateController(const char* Ratetype,ns3::UserDatabase &userDB,ns3::RateDatabase &userRD,uint64_t threshold=0);
	virtual ~RateControllerFactory();

private:
	std::map<std::string,ns3::RateController* (*)(ns3::UserDatabase&,ns3::RateDatabase&)> m_map;
};

#endif /* RATECONTROLLERFACTORY_H_ */
