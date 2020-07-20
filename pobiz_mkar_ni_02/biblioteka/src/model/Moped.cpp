//
// Created by student on 20.04.2020.

#include "model/Moped.h"
#include "model/VehicleException.hpp"

using namespace std;

Moped::Moped(const string &id, int baseRentPrice, float engineDisplacement)
                : MotorVehicle(id, baseRentPrice, engineDisplacement) {
    if(engineDisplacement <= 0) throw VehicleException(VehicleException::exceptionEngineDisplacement);

}

Moped::~Moped() {}

std::string Moped::vehicleInfo() {
    string _id = getId();
    int _baseRentPrice = getBaseRentPrice();
    float _engineDisplacement = getEngineDisplacement();

    string info = "\nNazwa: " + _id +
                  "\nPojemnosc: " + to_string(_engineDisplacement) +
                  "\nCena bazowa: " + to_string(_baseRentPrice);
    return info;
}

