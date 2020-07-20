//
// Created by student on 27.05.2020.
//

#ifndef MAL_LAT_CLIENTPREMIUM_H
#define MAL_LAT_CLIENTPREMIUM_H

#include "ClientType.h"
#include <string>

class clientPremium : public ClientType{
public:
    virtual float discount() override ;
    virtual int maxCars() override ;
    virtual std::string getClientType() override ;
};


#endif //MAL_LAT_CLIENTPREMIUM_H
