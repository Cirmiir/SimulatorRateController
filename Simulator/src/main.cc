/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "Simulator.h"
#include "Channel.h"
#include "Client.h"
#include "Rate.h"
#include <cstring>
#include "UsuallyChannel.h"

int main(int argv,char** args){
	UsuallyChannel channel(50 * RATE_GRANULARITY * 5);
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
	std::cout <<"Client		:"<< Clients <<"\n"<<"Step		:"<< Step <<"\n"<<"FinishTime	:"<< FinishTime <<"\n";
	std::map<ns3::Ipv4Address, Client> client;
	for (int D = 0; D < 4; ++D){
	  	int A=0;
	  	int B=0;
	  	int C=0;
	  	std::ostringstream subnet;
	  	subnet<<A<<"."<<B<<"."<<C<<"."<<D;
    	
      	enum ns3::UserTarif plan[3]={ns3::eUserTarifBronze,ns3::eUserTarifSilver,ns3::eUserTarifGold};
     	enum ns3::UserQuality plan2[3]={ns3::e480p,ns3::e720p,ns3::e1080p};
     	 
      	ns3::Ipv4Address address = ns3::Ipv4Address(subnet.str().c_str());
      	 

		Client *cl;
		if (D == 2)
		{
			cl = new Client(50*5000000,address,plan[0],plan2[2]);
		}
		else{	
			cl = new Client(50*5000000,address,plan[0],plan2[0]);
		}
		(client).insert(std::pair<ns3::Ipv4Address,Client>(address,*cl));
		

	}
	Simulator sim = Simulator(Clients,channel,0.01,file);
	sim.setClients(client);
	
	sim.Run(FinishTime);
    
}


