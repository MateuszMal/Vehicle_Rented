//
// Created by student on 19.04.2020.
//

#include <model/MotorVehicle.h>
#include "model/VehicleException.hpp"

using namespace std;


MotorVehicle::MotorVehicle(const string &id, int baseRentPrice, float engineDisplacement)
        : Vehicle(id, baseRentPrice), engineDisplacement(engineDisplacement) {
    if(engineDisplacement <= 0) throw VehicleException(VehicleException::exceptionEngineDisplacement);
    setActualRentPrice();
}

MotorVehicle::~MotorVehicle() {}

float MotorVehicle::getEngineDisplacement() const {
    return engineDisplacement;
}

void MotorVehicle::setActualRentPrice()
{
    if (engineDisplacement < 1000) actualRentPrice = Vehicle::getBaseRentPrice();
    else if (engineDisplacement >= 1000 and engineDisplacement < 2000)
        actualRentPrice =  Vehicle::getBaseRentPrice() * (1 + (engineDisplacement - 1000) / 1000 * 0.5);
    else if (engineDisplacement >= 2000) actualRentPrice = 1.5 * Vehicle::getBaseRentPrice();
}

float MotorVehicle::getActualRentPrice() const {
    return actualRentPrice;
}
