//
// Created by student on 22.06.2020.
//

#include "model/RentsManagerException.h"

using namespace std;

RentsManagerException::RentsManagerException(const std::string &arg) : logic_error(arg){}

const string RentsManagerException::exceptionRentsManagerNullPtr = "RENT_PTR IS NULL";
const string RentsManagerException::exceptionRentsManagerVehicleIsRented = "VEHICLE IS ALREADY RENTED";
const string RentsManagerException::exceptionRentsManagerNoExist = "RENT IS NOT EXIST";
