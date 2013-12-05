/* 
 * File:   UserDatabase.h
 * Author: simon
 *
 * Created on August 26, 2013, 8:07 PM
 */


#include "ipv4-address.h"
#include <map>

#ifndef USERDATABASE_H
#define	USERDATABASE_H

namespace ns3 {

    enum UserTarif {
        eUserTarifGold = 0,
        eUserTarifSilver = 1,
        eUserTarifBronze = 2
    };

    class UserDatabase {
    public:
        UserDatabase();
        virtual ~UserDatabase();

        UserDatabase(const UserDatabase &obj)
        {
            m_mapUsers = obj.m_mapUsers;
        }

        UserDatabase operator=(UserDatabase obj)
        {
            m_mapUsers = obj.m_mapUsers;
            return *this;
        }

        void RegisterUser(Ipv4Address addr, enum UserTarif tarif){
        	m_mapUsers.insert(std::pair<Ipv4Address, enum UserTarif>(addr,tarif));
        };

        std::map<Ipv4Address, enum UserTarif>& getMapUsers() {
            return m_mapUsers;
        }

        static std::string getNameForTarif(UserTarif userTarif) {
            static const char *names[] = {"Gold", "Silver", "Bronze"};

            return names[userTarif];
        }

        std::string getTarifForUser(Ipv4Address address) {
            static const char *names[] = {"Gold", "Silver", "Bronze"};
            return names[m_mapUsers.find(address)->second];
        }

    private:
        std::map<Ipv4Address, enum UserTarif> m_mapUsers;

    };
}

#endif	/* USERDATABASE_H */
