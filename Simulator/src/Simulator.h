/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "RateControllers/RateController.h"
#include "RateControllers/FirstRateController.h"
#include "RateControllers/SecondRateController.h"
#include "RateControllers/ThirdRateController.h"
#include "RateDatabase.h"
#include "math.h"
#include "Client.h"
#include "Channel.h"
#include "SinStream.h"
#include <list>
#include <map>
#include <iostream>
#include <fstream>
#include "FrequencyController.h"
#ifndef SIMULATOR_H
#define SIMULATOR_H

class Simulator
{
public:

	Simulator(uint32_t client, Channel &chan,double step,std::string file);
	~Simulator();
	uint64_t MapSum();
	void Step();
	void Run(double finish);
	void AddClient(Client client);
	void setClients(std::map<ns3::Ipv4Address, Client> &clients);
	//std::ostringstream GetNextIpv4Address()
	//{
	//	std::ostringstream subnet;
	//	subnet<<m_A<<"."<<m_B<<"."<<m_C<<"."<<m_D;
	//	return subnet;
	//};

private:
	std::ofstream *files;
	double stepTime;
	double m_time;
	double prevTime;
	Channel &m_channel;
	ns3::RateController *rate;
	ns3::FrequencyController *frequency;
	std::map<ns3::Ipv4Address, Client> *m_clients;

	int m_A;
	int m_B;
	int m_C;
	int m_D;
};
#endif
