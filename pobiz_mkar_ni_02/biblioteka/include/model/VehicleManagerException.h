//
// Created by student on 30.06.2020.
//

#ifndef MAL_LAT_VEHICLEMANAGEREXCEPTION_H
#define MAL_LAT_VEHICLEMANAGEREXCEPTION_H

#include <stdexcept>

class VehicleManagerException : public std::logic_error{
public:
    explicit VehicleManagerException(const std::string &);
    static const std::string exceptionVehicleManagerNullPtr;
    static const std::string exceptionVehicleManagerNoExist;
    static const std::string exceptionVehicleManagerVehicleIsExist;
};


#endif //MAL_LAT_VEHICLEMANAGEREXCEPTION_H
