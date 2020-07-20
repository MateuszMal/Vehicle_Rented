//
// Created by student on 04.04.2020.
//

#ifndef MAL_LAT_VEHICLE_H
#define MAL_LAT_VEHICLE_H

#include <string>
#include <memory>

class Vehicle {
private:
    const std::string id;
    int baseRentPrice;

public:
    Vehicle(const std::string &id, int baseRentPrice);
    virtual ~Vehicle();
    int getBaseRentPrice() const;
    const std::string &getId() const;
    virtual std::string vehicleInfo();
    virtual void setActualRentPrice() = 0;
    void setBaseRentPrice(int baseRentPrice);
    bool operator == (const Vehicle & V);
};
typedef std::shared_ptr<Vehicle> VehiclePtr;
#endif //MAL_LAT_VEHICLE_H
