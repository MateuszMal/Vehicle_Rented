//
// Created by student on 16.06.2020.
//

#ifndef MAL_LAT_CLIENTREPOSITORYEXCEPTION_HPP
#define MAL_LAT_CLIENTREPOSITORYEXCEPTION_HPP

#include <stdexcept>

class ClientReposiroryException : public std::logic_error{
public:
    explicit ClientReposiroryException(const std::string&);
    static const std::string exceptionNoClient;
    static const std::string exceptionClientPtrNullPtr;
    static const std::string exceptionClientExist;
};

#endif //MAL_LAT_CLIENTREPOSITORYEXCEPTION_HPP
