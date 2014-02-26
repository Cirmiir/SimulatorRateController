/*
 * FrequencyControllerFactory.cpp
 *
 *  Created on: 25 февр. 2014 г.
 *      Author: Саха
 */

#include "FrequencyControllerFactory.h"

FrequencyControllerFactory::FrequencyControllerFactory() {
	// TODO Auto-generated constructor stub
	m_map["First"] = &ns3::FirstFrequencyController::create;
}

FrequencyControllerFactory::~FrequencyControllerFactory() {
	// TODO Auto-generated destructor stub
}

ns3::FrequencyController* FrequencyControllerFactory::createController(const char* controllertype)
{

	if((m_map.find(controllertype)) == (m_map.end()))
		return 0;

	return m_map.find(controllertype)->second();
}
