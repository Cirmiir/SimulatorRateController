/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef STREAM_H
#define STREAM_H
#include "math.h"
#include <map>
#include "ns3/ipv4-address.h"

class Stream
{
public:
	Stream();
	virtual ~Stream();
	virtual double detValue();

};
#endif

