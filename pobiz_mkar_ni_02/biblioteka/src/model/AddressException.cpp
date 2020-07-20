//
// Created by student on 14.06.2020.
//

#include "model/AddressException.hpp"

using namespace std;

AddressException::AddressException(const string& arg) : logic_error(arg){}

const string AddressException::exceptionStreet = "INVALI STREET NAME";
const string AddressException::exceptionNumber = "INVALID NUMBER";