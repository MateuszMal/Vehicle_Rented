//
// Created by student on 14.05.2020.
//

#ifndef MAL_LAT_RENTEXCEPTION_H
#define MAL_LAT_RENTEXCEPTION_H

#include <stdexcept>

using namespace std;

class RentException : public logic_error
{
public:
    explicit RentException(const string&);
    static const string exceptionClientNullPtr;
    static const string exceptionVehicleNullPtr;
    static const string exceptionDays;
};


#endif //MAL_LAT_RENTEXCEPTION_H
