/*
 * ChannelFactory.h
 *
 *  Created on: 03 февр. 2014 г.
 *      Author: Саха
 */

#ifndef CHANNELFACTORY_H_
#define CHANNELFACTORY_H_
#include "Channel.h"
#include "Channels/UsuallyChannel.h"
#include "Channels/GreedChannel.h"
#include <map>

class ChannelFactory {
public:
	ChannelFactory();
	Channel* CreateChannel(std::string channeltype,uint64_t maxEnbodedSpeed);
	~ChannelFactory();

private:
	std::map<std::string,Channel* (*)(uint64_t)> map;
};

#endif /* CHANNELFACTORY_H_ */
