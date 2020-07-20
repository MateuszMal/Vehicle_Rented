//
// Created by student on 14.06.2020.
//

#include "model/VehicleException.hpp"

using namespace std;

VehicleException::VehicleException(const string &arg) : logic_error(arg) {}

const string VehicleException::exceptionId = "INVALID ID";
const string VehicleException::exceptionBaseRentPrice = "INVALID BASE RENT PRICE";
const string VehicleException::exceptionEngineDisplacement = "INVALID ENGINE DISPLACEMENT";
const string VehicleException::exceptionSegment = "INVALID SEGMENT";

