//
// Created by student on 19.04.2020.
//

#ifndef MAL_LAT_BICYCLE_H
#define MAL_LAT_BICYCLE_H


#include <model/Vehicle.h>

class Bicycle : public Vehicle{
private:
    float actualRentPrice;

public:
    Bicycle(const std::string &id, int baseRentPrice);
    ~Bicycle();
    virtual void setActualRentPrice();
    std::string vehicleInfo() override ;

};


#endif //MAL_LAT_BICYCLE_H
