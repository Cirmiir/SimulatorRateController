/*
 * ChannelFactory.cpp
 *
 *  Created on: 03 февр. 2014 г.
 *      Author: Саха
 */

#include "ChannelFactory.h"

ChannelFactory::ChannelFactory() {
	// TODO Auto-generated constructor stub

	map["UsuallyChannel"] = &UsuallyChannel::Create;
	map["GreedChannel"] = &GreedChannel::Create;

}

ChannelFactory::~ChannelFactory() {
	// TODO Auto-generated destructor stub
}

Channel* ChannelFactory::CreateChannel(std::string channeltype,uint64_t maxEnbodedSpeed)
{
	std::cout << ChannelFactory::map.size();
	if((map.find(channeltype)) == (map.end()))
		return 0;

	return map.find(channeltype)->second(maxEnbodedSpeed);
}
