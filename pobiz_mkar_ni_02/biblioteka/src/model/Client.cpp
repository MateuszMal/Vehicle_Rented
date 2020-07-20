#include <iostream>
#include "./model/Client.h"
#include "./model/Address.h"
#include "./model/Rent.h"
#include "model/ClientException.h"
#include "model/clientStandard.h"

using namespace std;

Client::Client(const AddressPtr &address, const AddressPtr &registerAddress, const string &firstName,
               const string &lastName, const string &personalId) : address(address), registerAddress(registerAddress),
                                                                   firstName(firstName), lastName(lastName),
                                                                   personalID(personalId), clientType(new clientStandard) {
    if(address == nullptr) throw ClientException(ClientException::exceptionAddress);
    if(registerAddress == nullptr) throw ClientException(ClientException::exceptionAddress);
    if(firstName.empty()) throw ClientException(ClientException::exceptionFirstName);
    if(lastName.empty()) throw ClientException(ClientException::exceptionLastName);
    if(personalId.empty()) throw ClientException(ClientException::exceptionPersonalID);
}

Client::~Client(){}

string Client::clientInfo()
{
    if (address or registerAddress)
       {string fullInfo = firstName + " " + lastName + "\n" + personalID \
       + "\nAdres zameldowania: " + address->getAddressInfo() + \
        "\nAdres zamieszkania: " + registerAddress->getAddressInfo();
       allRents();
        return fullInfo;}
    else
        return "Brak adresu";
}

void Client::addRent(weakRentPtr r)
{
    if(r.lock() == nullptr) throw ClientException(ClientException::exceptionNullPtr);
    clientBalance += 1;
    rentVector.push_back(r);
}

void Client::allRents()
{
    vector<weakRentPtr>::iterator it;
    if(rentVector.size() != 0) {
        for(it=rentVector.begin(); it!=rentVector.end(); ++it){
            (*it).lock()->rentInfo();
            cout << endl;
        }
    }
}

void Client::removeRent(weakRentPtr r)
{
    if(r.lock() == nullptr) throw ClientException(ClientException::exceptionNullPtr);
    vector<weakRentPtr>::iterator it;
    for(it=rentVector.begin(); it!=rentVector.end(); ++it){
        if((*it).lock()->getId() == r.lock()->getId()){
            rentVector.erase(it);
            break;
        }
    }
}

int Client::totalRents()
{
    return rentVector.size();
}

const string &Client::getPersonalId() const {return personalID;}

const string &Client::getFirstName() const {return firstName;}

const string Client::getLastName() const {return lastName;}

const AddressPtr &Client::getAddress() const {
    return address;
}

const AddressPtr &Client::getRegisterAddress() const {
    return registerAddress;
}

void Client::setClientType(const ClientTypePtr &clientType) {
    Client::clientType = clientType;
}

const ClientTypePtr &Client::getType() const {
    return clientType;
}

list<RentPtr> Client::getallRents(){
    list<RentPtr> lista;
    for(auto & rent : rentVector){
         lista.push_back(rent.lock());
    }
    return lista;
}

int Client::getClientBalance() const {
    return clientBalance;
}

bool Client::operator == (const Client & Cl) {
    if(this->personalID == Cl.personalID)
        return true;
    else
        return false;
}

float Client::getDiscount() {
    return getType()->discount();
}

const vector<weakRentPtr> &Client::getRentVector() const {
    return rentVector;
}

int Client::getMaxCars() {
    return getType()->maxCars();
}




