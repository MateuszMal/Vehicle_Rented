//
// Created by student on 05.04.2020.
//

#ifndef MAL_LAT_RENT_H
#define MAL_LAT_RENT_H

#include <iostream>
#include <memory>
#include "model/Vehicle.h"
#include "model/Client.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <string>
#include <boost/uuid/uuid_generators.hpp>
#include "boost/date_time/local_time/local_time.hpp"

using namespace std;
using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace boost::uuids;

typedef std::shared_ptr<Client> ClientPtr;

class Rent : public std::enable_shared_from_this<Rent>{
private:
    uuid ID;
    local_date_time *rentDateTime;
    local_date_time *endDateTime;
    float totalPrice;
    int rentalLength;
    time_zone_ptr *timeZone;
    ClientPtr klient;
    VehiclePtr pojazd;
    ClientPtr addRent;
public:

    Rent(const ClientPtr &klient, const VehiclePtr &pojazd, boost::posix_time::ptime data);
    Rent(const ClientPtr &klient, const VehiclePtr &pojazd);
    VehiclePtr getVehicle();
    ClientPtr getClient();
    virtual ~Rent();
    void rentInfo();
    void endRent();
    float getPeriod();
    const uuid &getId() const;
    float getPrice();
    local_date_time *getRentDateTime() const;
    local_date_time *getEndDateTime() const;
    int getRentalLength();
    int basePrice();
    void setClient();
    bool operator == (const Rent & R);
    void addClientRent();

};
typedef std::shared_ptr<Rent> RentPtr;
typedef std::weak_ptr<Rent> weakRentPtr;
#endif //MAL_LAT_RENT_H
