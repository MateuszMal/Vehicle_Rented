//
// Created by student on 24.04.2020.
//

#ifndef MAL_LAT_VEHICLEREPOSITORY_H
#define MAL_LAT_VEHICLEREPOSITORY_H

#include "Repository.h"
#include <model/Rent.h>
#include <vector>

class Vehicle;

using namespace std;

class VehicleRepository : public Repository<Vehicle>{
private:
    vector<VehiclePtr> vehicleRepository{};
public:
    VehicleRepository();
    virtual ~VehicleRepository();
    void create(VehiclePtr&) override ;
    void remove(VehiclePtr&) override ;
    void remove(int index) override;
    std::string getAll() override;
    shared_ptr<Vehicle> find(int index) override;
    bool find(shared_ptr<Vehicle> &ptr) override;
    void getVehicle(int index);
    void vehicleRaport();
    const vector<VehiclePtr> &getVehicleRepository() const;

};
typedef std::shared_ptr<VehicleRepository> VehicleRepositoryPtr;

#endif //MAL_LAT_VEHICLEREPOSITORY_H
