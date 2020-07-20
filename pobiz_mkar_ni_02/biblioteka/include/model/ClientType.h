//
// Created by student on 26.05.2020.
//

#ifndef MAL_LAT_CLIENTTYPE_H
#define MAL_LAT_CLIENTTYPE_H

#include <string>
#include <memory>

class ClientType{
public:
    virtual float discount() = 0;
    virtual int maxCars() = 0;
    virtual ~ClientType() = default;
    virtual std::string getClientType() = 0;
};

typedef std::shared_ptr<ClientType> ClientTypePtr;
#endif //MAL_LAT_CLIENTTYPE_H
