/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "Simulator.h"
#include "Channels/Channel.h"
#include "Client.h"
#include "Rate.h"
#include <cstring>
#include "ChannelFactory.h"
int main(int argv,char** args){
	Channel* channel = ChannelFactory().CreateChannel("GreedChannel",50 * RATE_GRANULARITY * 5);

	if (channel == 0)
	{
		std::cout << "not work";
		return -1;
	}

	double FinishTime = 0.6;
	double Step = 0.01;
	int Clients = 5;
	char* file = new char[100];
	if(argv >= 2)
		Clients = atoi(args[1]) ;
	if(argv >= 3)
		Step = atof(args[2]);
	if(argv >= 4)
		FinishTime = atof(args[3]);
	if(argv >= 5)
		file = strcpy(file, args[4]);
	else
		file = strcpy(file,"example.txt");
	std::cout 	<<"Client		:"<< Clients <<"\n"
				<<"Step		:"<< Step <<"\n"
				<<"FinishTime	:"<< FinishTime <<"\n";

	ClientList client;
	for (int D = 0; D < 4; ++D){
	  	int A=0;
	  	int B=0;
	  	int C=0;
	  	std::ostringstream subnet;
	  	subnet<<A<<"."<<B<<"."<<C<<"."<<D;
      	ns3::Ipv4Address address = ns3::Ipv4Address(subnet.str().c_str());

		Client *cl;
		if (D == 2)
		{
			cl = new Client(50*5000000,"10.0.0.1","Gold","480p");
		}
		else{	
			cl = new Client(50*5000000,address,"Bronze","1080p");
		}
		(client).insert(NodeList(address,*cl));
		

	}
	Simulator sim = Simulator(Clients, *channel,0.01,file,"First",500000);
	sim.setClients(client, "First");
	
	sim.Run(FinishTime);
    
}


