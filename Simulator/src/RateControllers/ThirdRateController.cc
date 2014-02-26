#include "ThirdRateController.h"

namespace ns3{

	void ThirdRateController::doLoadBalancing(std::map<Ipv4Address, uint64_t> &mapNewRates, uint64_t curEnodebSpeed)
		{
			
			if(m_previsionEnodebSpeed <= getMapSum(mapNewRates)){
				m_maxEnodebSpeed += m_add;
			}
			else
			{
				setMaxEnodebSpeed(getMapSum(mapNewRates));
			}
			uint64_t ra = ceilRate(m_maxEnodebSpeed / mapNewRates.size());

			int bronze=0, silver=0, gold=0;
			for (std::map<Ipv4Address, uint64_t>::iterator it = mapNewRates.begin(); it != mapNewRates.end(); ++it)
			{
				switch(m_userDB.getMapUsers().find(it->first)->second){
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
				it->second = m_maxBitrate;		
			}

			if (ra >= m_maxBitrate)
				return;

			if (ra >= m_midBitrate)
			{
				for (std::map<Ipv4Address, uint64_t>::iterator it = mapNewRates.begin(); it != mapNewRates.end(); ++it)
						it->second = m_midBitrate;

				int64_t sum = int64_t (m_maxEnodebSpeed) - int64_t(bronze)*m_midBitrate;
				if ((sum - int64_t((gold+silver)*m_maxBitrate)) > 0) 
				{
					for (std::map<Ipv4Address, uint64_t>::iterator it = mapNewRates.begin(); it != mapNewRates.end(); ++it)
						if((m_userDB.getMapUsers().find(it->first)->second)!=eUserTarifBronze)
							it->second = m_maxBitrate;

					m_previsionEnodebSpeed = getMapSum(mapNewRates);
					return;
				}
				if ((sum - int64_t((gold)*m_maxBitrate) - int64_t(silver*m_midBitrate)) > 0) 
				{
					for (std::map<Ipv4Address, uint64_t>::iterator it = mapNewRates.begin(); it != mapNewRates.end(); ++it)
						if((m_userDB.getMapUsers().find(it->first)->second)==eUserTarifGold)
							it->second = m_maxBitrate;
					m_previsionEnodebSpeed = getMapSum(mapNewRates);
					return;
				}

			}

			if (ra >= m_minBitrate)
			{
				for (std::map<Ipv4Address, uint64_t>::iterator it = mapNewRates.begin(); it != mapNewRates.end(); ++it)
						it->second = m_minBitrate;

				int64_t sum = int64_t (m_maxEnodebSpeed) - int64_t((bronze)*m_minBitrate);

				if ((sum - int64_t((gold+silver)*m_maxBitrate)) > 0) 
				{
					for (std::map<Ipv4Address, uint64_t>::iterator it = mapNewRates.begin(); it != mapNewRates.end(); ++it)
						if((m_userDB.getMapUsers().find(it->first)->second)!=eUserTarifBronze)
							it->second = m_maxBitrate;
					m_previsionEnodebSpeed = getMapSum(mapNewRates);
					return;
				}
				if ((sum - int64_t(gold)*m_maxBitrate - int64_t((silver)*m_midBitrate)) > 0) 
				{
					for (std::map<Ipv4Address, uint64_t>::iterator it = mapNewRates.begin(); it != mapNewRates.end(); ++it)
					{
						if((m_userDB.getMapUsers().find(it->first)->second)==eUserTarifGold)
							it->second = m_maxBitrate;
						if((m_userDB.getMapUsers().find(it->first)->second)==eUserTarifSilver)
							it->second = m_midBitrate;
					}
					m_previsionEnodebSpeed = getMapSum(mapNewRates);
					return;
				}
				bool change = false;
				if ((sum - int64_t((gold+silver)*m_midBitrate) > 0)) 
				{
					for (std::map<Ipv4Address, uint64_t>::iterator it = mapNewRates.begin(); it != mapNewRates.end(); ++it)
						if((m_userDB.getMapUsers().find(it->first)->second)!=eUserTarifBronze)
							it->second = m_midBitrate;

					change = true;
				}
				if ((sum - int64_t((gold)*m_maxBitrate+silver*m_minBitrate) > 0)) 
				{
					if ((sum - int64_t((gold)*m_maxBitrate+silver*m_minBitrate)<(sum - int64_t((gold+silver)*m_midBitrate))))
					{

						for (std::map<Ipv4Address, uint64_t>::iterator it = mapNewRates.begin(); it != mapNewRates.end(); ++it){
							if((m_userDB.getMapUsers().find(it->first)->second)==eUserTarifGold)
								it->second = m_maxBitrate;
							if((m_userDB.getMapUsers().find(it->first)->second)==eUserTarifSilver)
								it->second = m_minBitrate;
						}
						m_previsionEnodebSpeed = getMapSum(mapNewRates);
						return;
					}
				}
				if (change)
				{
					m_previsionEnodebSpeed = getMapSum(mapNewRates);
					return;
				}
				change = false;
				if ((sum - int64_t(((gold)*m_midBitrate) + silver*m_minBitrate)) > 0) 
				{
					for (std::map<Ipv4Address, uint64_t>::iterator it = mapNewRates.begin(); it != mapNewRates.end(); ++it)
						if((m_userDB.getMapUsers().find(it->first)->second)==eUserTarifGold)
							it->second = m_midBitrate;
					m_previsionEnodebSpeed = getMapSum(mapNewRates);
					return;
				}

			}

			m_previsionEnodebSpeed = getMapSum(mapNewRates);
		};


}
