//
// Created by student on 30.06.2020.
//

#include "model/ClientManagerExceptions.h"

using namespace std;

ClientManagerExceptions::ClientManagerExceptions(const std::string &arg) : logic_error(arg){}

const string ClientManagerExceptions::exceptionClientManagerNullPtr = "CLIENT_PTR IS NULL";
const string ClientManagerExceptions::exceptionClientManagerClientIsExist = "CLIENT IS ALREADY IN REPOSITORY";
const string ClientManagerExceptions::exceptionClientManagerNoExist = "CLIENT IS NOT EXIST";