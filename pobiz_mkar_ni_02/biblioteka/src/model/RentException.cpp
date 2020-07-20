//
// Created by student on 14.05.2020.
//
#include "model/RentException.h"

RentException::RentException(const string& arg) : logic_error(arg)
{}

const string RentException::exceptionClientNullPtr = "INVALID CLIENT (NULL)";
const string RentException::exceptionVehicleNullPtr = "INVALID VEHICLE (NULL)";
const string RentException::exceptionDays = "INVALID NUMBER OF DAYS TO SUBSTRACT (NEGATIVE VALUE)";
;

