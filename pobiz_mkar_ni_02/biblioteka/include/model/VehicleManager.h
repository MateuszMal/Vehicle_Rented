//
// Created by student on 31.05.2020.
//

#ifndef MAL_LAT_VEHICLEMANAGER_H
#define MAL_LAT_VEHICLEMANAGER_H

#include <memory>

class Vehicle;
class VehicleRepository;

typedef std::shared_ptr<Vehicle> VehiclePtr;
typedef std::shared_ptr<VehicleRepository> VehicleRepositoryPtr;

class VehicleManager{
private:
    VehicleRepositoryPtr currentRepository;
    VehicleRepositoryPtr archiveRepository;
public:
    VehicleManager();
    void addVehicle(VehiclePtr vehicle);
    void removeVehicle(VehiclePtr vehicle);
    void removeVehicle(int index);
    int numberOfCurrentVehicle();
    int numberOfArchiveVehicle();

};

typedef std::shared_ptr<VehicleManager> VehicleManagerPtr;


#endif //MAL_LAT_VEHICLEMANAGER_H
