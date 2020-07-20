//
// Created by student on 14.05.2020.
//

#ifndef MAL_LAT_CLIENTEXCEPTION_H
#define MAL_LAT_CLIENTEXCEPTION_H
#include <stdexcept>

class ClientException : public std::logic_error
{
public:
    explicit ClientException(const std::string&);
    static const std::string exceptionFirstName;
    static const std::string exceptionLastName;
    static const std::string exceptionPersonalID;
    static const std::string exceptionAddress;
    static const std::string exceptionNullPtr;
};

#endif //MAL_LAT_CLIENTEXCEPTION_H