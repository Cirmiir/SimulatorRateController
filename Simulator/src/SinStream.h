/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef SIN_STREAM_H
#define SIN_STREAM_H
#include "Stream.h"
#define _USE_MATH_DEFINES

class SinStream
{
public:

	SinStream(int Amplituda = 1,int Min = 0,int Freq = 1):A(Amplituda),M(Min),F(Freq){};
	~SinStream();
	double detValue(double time)
	{
		return A*sin(M_PI*2*F*time)+M;
	};

private:
	int A;
	int M;
	int F;

};
#endif

