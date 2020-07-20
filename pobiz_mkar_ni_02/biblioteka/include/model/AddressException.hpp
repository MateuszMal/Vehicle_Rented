//
// Created by student on 14.06.2020.
//

#ifndef MAL_LAT_ADDRESSEXCEPTION_HPP
#define MAL_LAT_ADDRESSEXCEPTION_HPP

#include <stdexcept>

class AddressException : public std::logic_error{
public:
    explicit AddressException(const std::string&);
    static const std::string exceptionStreet;
    static const std::string exceptionNumber;
};

#endif //MAL_LAT_ADDRESSEXCEPTION_HPP
