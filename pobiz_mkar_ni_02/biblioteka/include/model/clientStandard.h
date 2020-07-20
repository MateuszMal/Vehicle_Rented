//
// Created by student on 26.05.2020.
//

#ifndef MAL_LAT_CLIENTSTANDARD_H
#define MAL_LAT_CLIENTSTANDARD_H

#include "ClientType.h"

class clientStandard : public ClientType{

public:
    float discount() override ;
    int maxCars() override ;
    std::string getClientType() override ;
};

#endif //MAL_LAT_CLIENTSTANDARD_H