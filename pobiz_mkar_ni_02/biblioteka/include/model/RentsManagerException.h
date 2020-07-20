//
// Created by student on 22.06.2020.
//

#ifndef MAL_LAT_RENTSMANAGEREXCEPTION_H
#define MAL_LAT_RENTSMANAGEREXCEPTION_H

#include <stdexcept>

class RentsManagerException : public std::logic_error {
public:
    explicit RentsManagerException(const std::string&);
    static const std::string exceptionRentsManagerNullPtr;
    static const std::string exceptionRentsManagerNoExist;
    static const std::string exceptionRentsManagerVehicleIsRented;
};


#endif //MAL_LAT_RENTSMANAGEREXCEPTION_H
