#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "Address.h"
#include "ClientType.h"
#include <vector>
#include <memory>
#include <list>

class Rent;
class clientStandard;

typedef std::shared_ptr<Rent> RentPtr;
typedef std::weak_ptr<Rent> weakRentPtr;

class Client {
private:
    AddressPtr address = nullptr;
    AddressPtr registerAddress = nullptr;
    std::string firstName;
    std::string lastName;
    std::string personalID;
    std::vector<weakRentPtr> rentVector;
    ClientTypePtr clientType;
    int clientBalance = 0;

public:
    Client(const AddressPtr &address, const AddressPtr &registerAddress, const std::string &firstName,
           const std::string &lastName, const std::string &personalId);
    ~Client();

    std::string clientInfo();
    const std::string &getPersonalId() const;
    const std::string &getFirstName() const;
    const std::string getLastName() const;
    int totalRents();
    void addRent(weakRentPtr r);
    void allRents();
    void removeRent(weakRentPtr r);
    const AddressPtr &getAddress() const;
    const AddressPtr &getRegisterAddress() const;
    const ClientTypePtr &getType() const;
    void setClientType(const ClientTypePtr &clientType);
    std::list<RentPtr> getallRents();
    int getClientBalance() const;
    float getDiscount();
    int getMaxCars();
    bool operator == (const Client & Cl);
    const std::vector<weakRentPtr> &getRentVector() const;
};
typedef std::shared_ptr<Client> ClientPtr;
#endif