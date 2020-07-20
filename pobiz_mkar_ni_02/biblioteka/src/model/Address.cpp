//
// Created by student on 21.03.2020.
//

#include "model/Address.h"
#include "model/AddressException.hpp"


using namespace std;

Address::Address(const string &street, const string &number) : street(street), number(number) {
    if(street.empty()) throw AddressException(AddressException::exceptionStreet);
    if(number.empty()) throw AddressException(AddressException::exceptionNumber);
}

Address::Address(){}


string Address::getAddressInfo(){
    string fullAddress = street + " " + number;
    return fullAddress;
}

string Address::AddressGetNumber() {return number;}
string Address::AddressGetStreet() {return street;}