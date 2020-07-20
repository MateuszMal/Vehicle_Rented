//
// Created by student on 26.05.2020.
//

#ifndef MAL_LAT_CLIENTREGULAR_H
#define MAL_LAT_CLIENTREGULAR_H

#include <string>
#include "ClientType.h"

class clientRegular : public ClientType{
public:
    float discount() override ;
    int maxCars() override ;
    std::string getClientType() override ;
};

#endif //MAL_LAT_CLIENTREGULAR_H
