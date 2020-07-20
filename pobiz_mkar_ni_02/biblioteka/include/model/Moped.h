//
// Created by student on 20.04.2020.
//

#ifndef MAL_LAT_MOPED_H
#define MAL_LAT_MOPED_H

#include <string>
#include "model/MotorVehicle.h"

class Moped : public MotorVehicle{

public:
    Moped(const std::string &id, int baseRentPrice, float engineDisplacement);
    ~Moped();
    std::string vehicleInfo() override ;
};

#endif //MAL_LAT_MOPED_H