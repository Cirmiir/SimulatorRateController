#include "Client.h"

Client::Client(uint64_t bitRate,ns3::Ipv4Address addres,ns3::UserTarif tarif,ns3::UserQuality quality):address(addres),m_bitRate(bitRate){
	m_maxbitRate = 0;
	m_condition = 1.5;
	m_startTime = 0;
	m_tarif = tarif;
	m_quality = quality;

};
Client::~Client(){};