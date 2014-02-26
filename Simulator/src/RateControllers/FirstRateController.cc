#include "FirstRateController.h"

namespace ns3{

	void FirstRateController::doLoadBalancing(std::map<Ipv4Address, uint64_t> &mapNewRates, uint64_t curEnodebSpeed)
		{
			uint64_t rate[3]={RATE_GRANULARITY*100, RATE_GRANULARITY*300,RATE_GRANULARITY*5000};
			if(m_previsionEnodebSpeed <= getMapSum(mapNewRates)){
				m_maxEnodebSpeed += m_add;
			}
			else
			{
				setMaxEnodebSpeed(getMapSum(mapNewRates));
			}
			//m_maxEnodebSpeed = getMapSum(mapNewRates);
			uint64_t ra = ceilRate(m_maxEnodebSpeed / mapNewRates.size());
			int bronze=0, silver=0, gold=0;
			for (std::map<Ipv4Address, uint64_t>::iterator it = mapNewRates.begin(); it != mapNewRates.end(); ++it)
			{
				it->second = 0;
				int size = m_userDB.getMapUsers().size();
				UserTarif cases= m_userDB.getMapUsers().find(it->first)->second;
				switch(cases){
					case eUserTarifBronze:
						bronze++;
						break;
					case eUserTarifSilver:
						silver++;
						break;
					case eUserTarifGold:
						gold++;
						break;
					}			
			}
			if (ra == 0)
			{
				m_previsionEnodebSpeed =0;
				return;
			}
			for (std::map<Ipv4Address, uint64_t>::iterator it = mapNewRates.begin(); it != mapNewRates.end(); ++it)
			{
				it->second = ra;
				uint64_t t;
				switch(m_userDB.getMapUsers().find(it->first)->second){
					case eUserTarifBronze:
						t = ceilRate(ra > m_threshold ? ra - m_threshold: 0);
						it->second = Min(t,rate[m_userRD.getTarif(it->first)]);
						break;
					case eUserTarifSilver:
						it->second = ra;
						break;
					case eUserTarifGold:
						if(gold <= bronze)
							it->second = ceilRate(Min(ceilRate(ra + m_threshold),rate[m_userRD.getTarif(it->first)]));
						else
							it->second = ceilRate(Min(ceilRate(ra +(m_threshold*bronze)/gold),rate[m_userRD.getTarif(it->first)]));
						break;
					}		
			}
			uint64_t sum = int64_t (m_maxEnodebSpeed) - int64_t(getMapSum(mapNewRates));

			ra = ceilRate(sum / (gold + silver + bronze)); 
			if (ra >= 1)
			{
				

				for (std::map<Ipv4Address, uint64_t>::iterator it = mapNewRates.begin(); it != mapNewRates.end(); ++it)
				{
					it->second = Min(ra + it->second,rate[m_userRD.getTarif(it->first)]);

				}
				m_previsionEnodebSpeed = getMapSum(mapNewRates);
				return;

			}
			ra = ceilRate(sum / (gold + silver));
			if (ra >= 1)
			{

				for (std::map<Ipv4Address, uint64_t>::iterator it = mapNewRates.begin(); it != mapNewRates.end(); ++it)
				{
					if((m_userDB.getMapUsers().find(it->first)->second)!=eUserTarifSilver)
						it->second = Min(ra + it->second,rate[m_userRD.getTarif(it->first)]);
				}

				m_previsionEnodebSpeed = getMapSum(mapNewRates);
				return;

			}
			ra = ceilRate(sum / (gold));
			if (ra >= 1)
			{
				for (std::map<Ipv4Address, uint64_t>::iterator it = mapNewRates.begin(); it != mapNewRates.end(); ++it)
				{
					if((m_userDB.getMapUsers().find(it->first)->second)==eUserTarifGold)
						it->second = Min(ra + it->second,rate[m_userRD.getTarif(it->first)]);
				}
				m_previsionEnodebSpeed = getMapSum(mapNewRates);
				return;
			}
			m_previsionEnodebSpeed = getMapSum(mapNewRates);
			return;

		}


}
