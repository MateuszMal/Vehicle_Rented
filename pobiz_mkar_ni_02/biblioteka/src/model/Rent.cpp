//
// Created by student on 05.04.2020.
//
#include <boost/uuid/uuid_generators.hpp>
#include "boost/date_time/local_time/local_time.hpp"
#include <model/Rent.h>
#include <model/Vehicle.h>
#include "model/RentException.h"

Rent::Rent(const ClientPtr &klient, const VehiclePtr &pojazd, ptime data) : klient(klient), pojazd(pojazd) {
    if(klient == nullptr) throw RentException(RentException::exceptionClientNullPtr);
    if(pojazd == nullptr) throw RentException(RentException::exceptionVehicleNullPtr);
    if(data.is_not_a_date_time()) throw RentException(RentException::exceptionDays);
    timeZone = new time_zone_ptr(new posix_time_zone("CET+0"));
    rentDateTime = new local_date_time(data, *timeZone);
    ID = random_generator()();
    totalPrice = 0;
    rentalLength = 0;
    endDateTime = nullptr;

}

Rent::Rent(const ClientPtr &klient, const VehiclePtr &pojazd) : klient(klient), pojazd(pojazd) {
    if(klient == nullptr) throw RentException(RentException::exceptionClientNullPtr);
    if(pojazd == nullptr) throw RentException(RentException::exceptionVehicleNullPtr);
    timeZone = new time_zone_ptr(new posix_time_zone("CET+0"));
    ptime pt(second_clock::local_time());
    rentDateTime = new local_date_time(pt, *timeZone);
    ID = random_generator()();
    totalPrice = 0;
    rentalLength = 0;
    endDateTime = nullptr;
}

Rent::~Rent(){
    rentDateTime = nullptr;
    endDateTime = nullptr;
    timeZone = nullptr;
    delete rentDateTime;
    delete endDateTime;
    delete timeZone;
}

void Rent::endRent(){
    ptime lt(second_clock::local_time());
    local_date_time *nowTime = new local_date_time(lt, *timeZone);
    endDateTime = new local_date_time(lt, *timeZone);
    rentalLength = getPeriod() + 1;
    if(klient->getType() == nullptr){
        totalPrice = rentalLength * pojazd->getBaseRentPrice();}
    else
        totalPrice = rentalLength * pojazd->getBaseRentPrice() * klient->getDiscount();
    klient->removeRent(shared_from_this());
}

float Rent::getPeriod(){
    float daysOfRental;
    ptime lt(second_clock::local_time());   //local time
    local_date_time *nowTime = new local_date_time(lt, *timeZone);
    time_duration period = local_time_period(*rentDateTime, *nowTime).length();
    daysOfRental = period.hours()/24;
    return daysOfRental;
}

VehiclePtr Rent::getVehicle(){
    return pojazd;
}

float Rent::getPrice(){
    return totalPrice;
}

int Rent::getRentalLength(){
    return rentalLength;
}

void Rent::rentInfo(){
    cout << "Rental info: " << endl;
    cout << ID << endl;

    cout << (*rentDateTime).local_time() << endl;
    if (endDateTime != nullptr) {
        cout << (*endDateTime).local_time() << endl;
        cout << totalPrice << endl;
        cout << rentalLength << endl;
    };
}

int Rent::basePrice(){
    int cena = pojazd->getBaseRentPrice();
    return cena;
}

ClientPtr Rent::getClient() {
    return  klient;
}

const uuid &Rent::getId() const {
    return ID;
}

local_date_time *Rent::getRentDateTime() const {
    return rentDateTime;
}

local_date_time *Rent::getEndDateTime() const {
    return endDateTime;
}

bool Rent::operator==(const Rent &R) {
    if(this->getId() == R.getId())
        return true;
    else
        return false;
}

void Rent::addClientRent() {
    klient->addRent(shared_from_this());
}
