//
// Created by student on 30.06.2020.
//

#ifndef MAL_LAT_CLIENTMANAGEREXCEPTIONS_H
#define MAL_LAT_CLIENTMANAGEREXCEPTIONS_H

#include <stdexcept>

class ClientManagerExceptions : public std::logic_error{
public:
    explicit ClientManagerExceptions(const std::string&);
    static const std::string exceptionClientManagerNullPtr;
    static const std::string exceptionClientManagerNoExist;
    static const std::string exceptionClientManagerClientIsExist;

};


#endif //MAL_LAT_CLIENTMANAGEREXCEPTIONS_H
