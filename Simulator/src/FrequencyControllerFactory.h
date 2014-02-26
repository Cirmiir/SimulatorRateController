/*
 * FrequencyControllerFactory.h
 *
 *  Created on: 25 ����. 2014 �.
 *      Author: ����
 */
#include "FrequencyControllers/FirstFrequencyController.h"
#include "FrequencyControllers/FrequencyController.h"
#ifndef FREQUENCYCONTROLLERFACTORY_H_
#define FREQUENCYCONTROLLERFACTORY_H_

class FrequencyControllerFactory {
public:
	FrequencyControllerFactory();
	virtual ~FrequencyControllerFactory();

	ns3::FrequencyController* createController(const char* controllertype);

private:
	std::map<std::string,ns3::FrequencyController* (*)()> m_map;
};

#endif /* FREQUENCYCONTROLLERFACTORY_H_ */
