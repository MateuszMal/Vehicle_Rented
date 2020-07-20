//
// Created by student on 16.06.2020.
//

#ifndef MAL_LAT_RENTSREPOSITORYEXCEPTION_HPP
#define MAL_LAT_RENTSREPOSITORYEXCEPTION_HPP

#include <stdexcept>

class RentsRepositoryException : public std::logic_error{
public:
    explicit RentsRepositoryException(const std::string&);
    static const std::string exceptionRentNullPtr;
    static const std::string exceptionRentNoExist;
    static const std::string exceptionRentExist;
    static const std::string exceptionRentVehicleIsRented;

};

#endif //MAL_LAT_RENTSREPOSITORYEXCEPTION_HPP
