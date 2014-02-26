#include "SecondRateController.h"

namespace ns3{

	void SecondRateController::doLoadBalancing(std::map<Ipv4Address, uint64_t> &mapNewRates, uint64_t curEnodebSpeed)
		{
			enum UserTarif plan[3] = {eUserTarifBronze,eUserTarifSilver,eUserTarifGold};
		uint64_t rate[3] = {m_minBitrate,m_midBitrate,m_maxBitrate};
		if(m_previsionEnodebSpeed <= getMapSum(mapNewRates)){
				setMaxEnodebSpeed(m_maxEnodebSpeed + m_add);			}
			else
			{
				setMaxEnodebSpeed(getMapSum(mapNewRates));
			}

		int tarif = 0;
		int bitrate = 2;
		for (std::map<Ipv4Address,uint64_t>::iterator it=mapNewRates.begin(); it!=mapNewRates.end(); ++it)
			it->second = rate[bitrate];
		while(getMapSum(mapNewRates) > m_maxEnodebSpeed)
		{
			for (std::map<Ipv4Address,uint64_t>::iterator it=mapNewRates.begin(); it!=mapNewRates.end(); ++it)
				if (m_userDB.getMapUsers().find(it->first)->second == plan[tarif])
					it->second = rate[bitrate];

			if(bitrate == 0)
			{
				tarif++;
				bitrate = 3;
			}
			if (tarif==2)
			{
				m_previsionEnodebSpeed = 0;
				return;
			}
			bitrate--;
		}
		m_previsionEnodebSpeed = getMapSum(mapNewRates); 
		};


}
