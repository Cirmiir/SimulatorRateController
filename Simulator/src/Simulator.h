/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "RateControllers/RateController.h"
#include "RateControllers/FirstRateController.h"
#include "RateControllers/SecondRateController.h"
#include "RateControllers/ThirdRateController.h"
#include "RateDatabase.h"
#include "math.h"
#include "Client.h"
#include "Channels/Channel.h"
#include "SinStream.h"
#include <list>
#include <map>
#include <iostream>
#include <fstream>
#include "FrequencyControllerFactory.h"
#include "FrequencyControllers/FrequencyController.h"

#ifndef SIMULATOR_H
#define SIMULATOR_H
typedef std::map<ns3::Ipv4Address, Client> ClientList;
typedef std::pair<ns3::Ipv4Address,Client> NodeList;

class Simulator
{
public:

	Simulator(uint32_t client, Channel &chan,double step,std::string file,const char* frequencyController, uint64_t RB);
	~Simulator();
	uint64_t MapSum();
	void Step();
	void Run(double finish);
	void AddClient(Client client);
	void setClients(ClientList &clients,const char* RateController);

private:
	std::ofstream *m_files;
	double stepTime;
	double m_time;
	double m_prevTime;
	Channel &m_channel;
	ns3::RateController *m_rate;
	ns3::FrequencyController *m_frequency;
	ClientList *m_clients;
};
#endif
