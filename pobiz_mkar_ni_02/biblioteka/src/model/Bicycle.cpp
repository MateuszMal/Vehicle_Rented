//
// Created by student on 19.04.2020.
//

#include "model/Bicycle.h"
#include <iostream>

using namespace std;

Bicycle::Bicycle(const std::string &id, int baseRentPrice) : Vehicle(id, baseRentPrice) {}

Bicycle::~Bicycle() {}

void Bicycle::setActualRentPrice() {
    actualRentPrice = getBaseRentPrice();
}

std::string Bicycle::vehicleInfo() {
    string _id = getId();
    int _baseRentPrice = getBaseRentPrice();
    string info = _id + ": " + to_string(_baseRentPrice);
    return info;
}
