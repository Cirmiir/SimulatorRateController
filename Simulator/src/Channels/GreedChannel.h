/*
 * GreedChannel.h
 *
 *  Created on: 03 ����. 2014 �.
 *      Author: ����
 */

#ifndef GREEDCHANNEL_H_
#define GREEDCHANNEL_H_

#include "../Channel.h"

class GreedChannel: public Channel {
public:
	GreedChannel(uint64_t maxEnbodedSpeed):Channel(maxEnbodedSpeed){};
	~GreedChannel();

	void transmit(ns3::Ipv4Address address, uint64_t speed);
	int64_t transmits(double time,uint64_t add);
	uint64_t EndTransmit();
	static Channel* Create(uint64_t maxEnbodedSpeed)
	{
		return new GreedChannel(maxEnbodedSpeed);
	};
};

#endif /* GREEDCHANNEL_H_ */
