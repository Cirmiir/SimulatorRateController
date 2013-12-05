/* 
 * File:   UserDatabase.h
 * Author: simon
 *
 * Created on August 26, 2013, 8:07 PM
 */


#include "ns3/ipv4-address.h"
#include <map>

#ifndef RATEDATABASE_H
#define	RATEDATABASE_H

namespace ns3 {

    enum UserQuality {
        e480p = 0,
        e720p = 1,
        e1080p = 2
    };

    class RateDatabase {
    public:
        RateDatabase();
        RateDatabase(const RateDatabase &obj)
        {
            m_mapUsers = obj.m_mapUsers;
        }

        virtual ~RateDatabase();
        void RegisterUser(Ipv4Address addr, enum UserQuality tarif){
        	m_mapUsers->insert(std::pair<Ipv4Address, enum UserQuality>(addr,tarif));
        };

        RateDatabase operator=(RateDatabase obj)
        {
            m_mapUsers = obj.m_mapUsers;
            return *this;
        }
        

        std::map<Ipv4Address, enum UserQuality>& getMapUsers() {
            return *m_mapUsers;
        }

        static std::string getNameForTarif(UserQuality userTarif) {
            static const char *names[] = {"480p", "720p", "1080p"};

            return names[userTarif];
        }

        int getTarif(Ipv4Address addr) {
            for (std::map<ns3::Ipv4Address, enum UserQuality>::iterator it=m_mapUsers->begin(); it!=m_mapUsers->end(); ++it)
            {
                if (it->first==addr)
                    return it->second;
            }
            return -1;
        }

    private:
        std::map<Ipv4Address, enum UserQuality> *m_mapUsers;

    };
}

#endif	/* USERDATABASE_H */
