//
// Created by student on 21.03.2020.
//
#ifndef MAL_LAT_ADDRESS_H
#define MAL_LAT_ADDRESS_H

#include <iostream>
#include <memory>

class Address {
private:
    std::string street;
    std::string number;

public:
    Address(const std::string &street, const std::string &number);
    Address();
    std::string AddressGetNumber();
    std::string AddressGetStreet();
    std::string getAddressInfo();
};
typedef std::shared_ptr<Address> AddressPtr;
#endif //MAL_LAT_ADDRESS_H
