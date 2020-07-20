//
// Created by student on 04.04.2020.
//

#include "model/Vehicle.h"
#include "model/VehicleException.hpp"
#include <string>
#include <iostream>

using namespace std;

Vehicle::Vehicle(const std::string &id, int baseRentPrice) : id(id), baseRentPrice(baseRentPrice) {
    if(id.empty()) throw VehicleException(VehicleException::exceptionId);
    if(baseRentPrice <= 0) throw VehicleException(VehicleException::exceptionBaseRentPrice);
}

Vehicle::~Vehicle() {}

string Vehicle::vehicleInfo()
{
    return id + ": " + to_string(baseRentPrice);
}

const string &Vehicle::getId() const
{
    return id;
}

int Vehicle::getBaseRentPrice() const
{
    return baseRentPrice;
}

bool Vehicle::operator==(const Vehicle &V) {
    if(this->getId() == V.getId())
        return true;
    else
        return false;
}

void Vehicle::setBaseRentPrice(int baseRentPrice) {
    Vehicle::baseRentPrice = baseRentPrice;
}

