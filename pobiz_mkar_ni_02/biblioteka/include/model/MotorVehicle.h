//
// Created by student on 19.04.2020.
//

#ifndef MAL_LAT_MOTORVEHICLE_H
#define MAL_LAT_MOTORVEHICLE_H

#include <string>
#include "Vehicle.h"

class MotorVehicle : public Vehicle {
private:
    float engineDisplacement;
    float actualRentPrice;

public:
    MotorVehicle(const std::string &id, int baseRentPrice, float engineDisplacement);
    virtual ~MotorVehicle();
    float getEngineDisplacement() const;
    virtual void setActualRentPrice();
    float getActualRentPrice() const;

};
#endif //MAL_LAT_MOTORVEHICLE_H