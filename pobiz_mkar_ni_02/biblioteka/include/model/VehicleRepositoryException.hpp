//
// Created by student on 16.06.2020.
//

#ifndef MAL_LAT_VEHICLEREPOSITORYEXCEPTION_HPP
#define MAL_LAT_VEHICLEREPOSITORYEXCEPTION_HPP

#include <stdexcept>

class VehicleRepositoryException : public std::logic_error{
public:
    explicit VehicleRepositoryException(const std::string&);
    static const std::string exceptionVehicleNoExist;
    static const std::string exceptionVehicleNullPtr;
    static const std::string exceptionVehicleExists;
};

#endif //MAL_LAT_VEHICLEREPOSITORYEXCEPTION_HPP
