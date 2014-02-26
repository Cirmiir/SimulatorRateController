#include "Client.h"

Client::Client(uint64_t bitRate,ns3::Ipv4Address addres,ns3::UserTarif tarif,ns3::UserQuality quality):address(addres),m_bitRate(bitRate){
	m_maxbitRate = 0;
	m_condition = 1.5;
	m_startTime = 0;
	m_tarif = tarif;
	m_quality = quality;

};
Client::Client(uint64_t bitRate,const char* addres,const char* tarif,const char* quality):address(ns3::Ipv4Address(addres)),m_bitRate(bitRate)
{
	m_maxbitRate = 0;
	m_condition = 1.5;
	m_startTime = 0;
	m_tarif = ns3::UserDatabase::getTarifForName(tarif);
	m_quality = ns3::RateDatabase::getTarifForName(quality);

};
Client::Client(uint64_t bitRate,ns3::Ipv4Address addres,const char* tarif,const char* quality):address(addres),m_bitRate(bitRate)
{
	m_maxbitRate = 0;
	m_condition = 1.5;
	m_startTime = 0;
	m_tarif = ns3::UserDatabase::getTarifForName(tarif);
	m_quality = ns3::RateDatabase::getTarifForName(quality);

};
Client::~Client(){};
void Client::printInfo()
{
	std::cout << "Bitrate for client "<<this->getAddress()<<"  "
				<< this->getNameTarif()<<"  "
				<< this->getNameQuality()<<" "
				<< this->getBitrate()/RATE_GRANULARITY <<"Kb " << "\n";;
	return;
}
