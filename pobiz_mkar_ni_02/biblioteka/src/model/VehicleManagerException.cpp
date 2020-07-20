//
// Created by student on 30.06.2020.
//

#include "model/VehicleManagerException.h"

using namespace std;

VehicleManagerException::VehicleManagerException(const std::string &arg) : logic_error(arg){}

const string VehicleManagerException::exceptionVehicleManagerNullPtr = "VEHICLE_PTR IS NULL";
const string VehicleManagerException::exceptionVehicleManagerVehicleIsExist = "VEHICLE IS ALREADY IN REPOSITORY";
const string VehicleManagerException::exceptionVehicleManagerNoExist = "VEHICLE IS NOT EXIST";