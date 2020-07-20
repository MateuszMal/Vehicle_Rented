//
// Created by student on 31.05.2020.
//

#include "model/VehicleManager.h"
#include "model/VehicleRepository.h"
#include "model/VehicleManagerException.h"

VehicleManager::VehicleManager() : currentRepository(new VehicleRepository),
                                    archiveRepository(new VehicleRepository) {}

void VehicleManager::addVehicle(VehiclePtr vehicle) {
    if(vehicle == nullptr) throw VehicleManagerException(VehicleManagerException::exceptionVehicleManagerNullPtr);
    for(const auto & v : currentRepository->getVehicleRepository()){
        if(vehicle == v) throw VehicleManagerException(VehicleManagerException::exceptionVehicleManagerVehicleIsExist);
        }
    currentRepository->create(vehicle);
}

void VehicleManager::removeVehicle(VehiclePtr vehicle) {
    if(vehicle == nullptr) throw VehicleManagerException(VehicleManagerException::exceptionVehicleManagerNullPtr);
    bool flag = false;
    for(const auto & v : currentRepository->getVehicleRepository()) {
        if (vehicle == v) {
            flag = true;
            currentRepository->remove(vehicle);
            archiveRepository->create(vehicle);
            break;
        }
    }
    if(flag == false) throw VehicleManagerException(VehicleManagerException::exceptionVehicleManagerNoExist);

}

void VehicleManager::removeVehicle(int index) {
    if(index > currentRepository->getVehicleRepository().size() or index < 0)
        throw VehicleManagerException(VehicleManagerException::exceptionVehicleManagerNoExist);
    currentRepository->remove(index);
}

int VehicleManager::numberOfCurrentVehicle() {
    return currentRepository->getVehicleRepository().size();
}

int VehicleManager::numberOfArchiveVehicle() {
    return archiveRepository->getVehicleRepository().size();
}


