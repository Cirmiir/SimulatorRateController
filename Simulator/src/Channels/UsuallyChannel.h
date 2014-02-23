/*
 * UsuallyChannel.h
 *
 *  Created on: 06 дек. 2013 г.
 *      Author: Саха
 */

#ifndef USUALLYCHANNEL_H_
#define USUALLYCHANNEL_H_

#include "../Channel.h"

class UsuallyChannel : public  Channel {
public:
	UsuallyChannel(uint64_t maxEnbodedSpeed):Channel(maxEnbodedSpeed)
	{};
	~UsuallyChannel();

	void transmit(ns3::Ipv4Address address, uint64_t speed);
	int64_t transmits(double time,uint64_t add);
	uint64_t EndTransmit();
	static Channel* Create(uint64_t maxEnbodedSpeed)
	{
		return new UsuallyChannel(maxEnbodedSpeed);
	};
};

#endif /* USUALLYCHANNEL_H_ */
