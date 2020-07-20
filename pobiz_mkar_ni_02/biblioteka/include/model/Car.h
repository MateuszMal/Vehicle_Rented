//
// Created by student on 22.04.2020.
//

#ifndef MAL_LAT_CAR_H
#define MAL_LAT_CAR_H

#include <string>
#include "model/MotorVehicle.h"


class Car : public MotorVehicle{
private:
    std::string segment;
//    float actualRentPrice;
public:

    Car(const std::string &id, int baseRentPrice, float engineDisplacement, std::string seg);
    ~Car();
    void setActualRentPrice() override ;
    const std::string &getSegment() const;
    void setSegment(const std::string &segment);

    std::string vehicleInfo() override ;
};

#endif //MAL_LAT_CAR_H
