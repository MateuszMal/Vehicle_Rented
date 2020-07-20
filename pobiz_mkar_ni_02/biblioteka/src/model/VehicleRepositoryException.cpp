//
// Created by student on 16.06.2020.
//

#include "model/VehicleRepositoryException.hpp"

using namespace std;

VehicleRepositoryException::VehicleRepositoryException(const string &arg) : logic_error(arg){}

const string VehicleRepositoryException::exceptionVehicleNoExist = "VEHICLE DOESN'T EXIST";
const string VehicleRepositoryException::exceptionVehicleNullPtr = "VEHICLE_PTR IS NULL";
const string VehicleRepositoryException::exceptionVehicleExists = "VEHICLE IS EXIST";