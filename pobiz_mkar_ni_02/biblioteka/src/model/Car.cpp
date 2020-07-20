//
// Created by student on 22.04.2020.
//

#include <string>
#include <model/Car.h>
#include <regex>
#include "model/VehicleException.hpp"


using namespace std;
const regex wzor("[A-E]");

Car::Car(const string &id,int baseRentPrice, float engineDisplacement, string seg)
            : MotorVehicle(id, baseRentPrice, engineDisplacement), segment(seg){
    if(engineDisplacement <= 0) throw VehicleException(VehicleException::exceptionEngineDisplacement);
    if(!regex_match(segment, wzor)) throw VehicleException(VehicleException::exceptionSegment);
    setActualRentPrice();
}

Car::~Car(){}

const string &Car::getSegment() const {
    return segment;
}

void Car::setActualRentPrice()
{
    float multiplier = 0;
    if(segment == "A") multiplier = 1;
    else if(segment == "B") multiplier = 1.1;
    else if(segment == "C") multiplier = 1.2;
    else if(segment == "D") multiplier = 1.3;
    else if(segment == "E") multiplier = 1.5;
    setBaseRentPrice(multiplier * MotorVehicle::getBaseRentPrice());
}

std::string Car::vehicleInfo() {
    string _id = getId();
    int _baseRentPrice = getBaseRentPrice();
    string _segment = getSegment();
    float _engineDisplacement = getEngineDisplacement();

    string info = "\nNazwa: " + _id + "\nSegment: " + _segment +
            "\nPojemnosc: " + to_string(_engineDisplacement) +
            "\nCena bazowa: " + to_string(_baseRentPrice);
    return info;
}





