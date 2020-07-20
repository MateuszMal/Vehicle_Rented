//
// Created by student on 14.05.2020.
//

#include "model/ClientException.h"

using namespace std;

ClientException::ClientException(const string &arg) : logic_error(arg)
{}

const string ClientException::exceptionFirstName = "INVALID FIRST NAME";
const string ClientException::exceptionLastName = "INVALID LAST NAME";
const string ClientException::exceptionPersonalID = "INVALID PERSONAL ID";
const string ClientException::exceptionAddress = "INVALID ADDRESS";
const string ClientException::exceptionNullPtr = "NULL PTR";
