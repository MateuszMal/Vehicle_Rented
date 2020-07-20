//
// Created by student on 14.06.2020.
//

#ifndef MAL_LAT_VEHICLEEXCEPTION_HPP
#define MAL_LAT_VEHICLEEXCEPTION_HPP

#include <stdexcept>

class VehicleException : public std::logic_error{
public:
    explicit VehicleException(const std::string&);
    static const std::string exceptionId;
    static const std::string exceptionBaseRentPrice;
    static const std::string exceptionEngineDisplacement;
    static const std::string exceptionSegment;
};

#endif //MAL_LAT_VEHICLEEXCEPTION_HPP


