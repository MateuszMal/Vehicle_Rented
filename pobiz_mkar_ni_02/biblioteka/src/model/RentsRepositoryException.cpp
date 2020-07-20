//
// Created by student on 16.06.2020.
//

#include "model/RentsRepositoryException.hpp"

using namespace std;

RentsRepositoryException::RentsRepositoryException(const std::string &arg) : logic_error(arg){}

const string RentsRepositoryException::exceptionRentNullPtr = "RENT_PTR IS NULL";
const string RentsRepositoryException::exceptionRentNoExist = "RENT DOESN'T EXIST";
const string RentsRepositoryException::exceptionRentExist = "RENT IS EXIST IN CURRENT REPOSITORY";
const string RentsRepositoryException::exceptionRentVehicleIsRented = "VEHICLE IS RENTED";