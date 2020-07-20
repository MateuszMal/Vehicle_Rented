//
// Created by student on 24.04.2020.
//

#include <model/VehicleRepository.h>
#include "model/PredicateTemplate.h"
#include "model/VehicleRepositoryException.hpp"
#include <iostream>

VehicleRepository::VehicleRepository() {}

VehicleRepository::~VehicleRepository() {}

void VehicleRepository::create(VehiclePtr &pojazd)
{
    if(pojazd == nullptr) throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleNullPtr);
    vehicleRepository.push_back(pojazd);
}


void VehicleRepository::remove(VehiclePtr &pojazd) {
    if(pojazd == nullptr) throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleNullPtr);
    for (int i=0;i<vehicleRepository.size();i++)
        if(vehicleRepository[i] == pojazd) {
            vehicleRepository.erase(vehicleRepository.begin() + i );
        }
}

void VehicleRepository::remove(int index) {
    vehicleRepository.erase(vehicleRepository.begin() + index);
}

void VehicleRepository::vehicleRaport() {
    for(int i=0;i<vehicleRepository.size();i++){
        std::cout << vehicleRepository[i]->vehicleInfo();
        }

}

const vector<VehiclePtr> &VehicleRepository::getVehicleRepository() const {
    return vehicleRepository;
}

void VehicleRepository::getVehicle(int index)
{
    if(index > vehicleRepository.size() or index < 0)
        throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleNoExist);
    int nr = 0;
    for (int i=0;i<vehicleRepository.size();i++)
    {
        if (nr==index)
        {
            vehicleRepository[nr]->vehicleInfo();
        }
        nr+=1;

    }
}


std::string VehicleRepository::getAll() {
    return std::__cxx11::string();
}

shared_ptr<Vehicle> VehicleRepository::find(int index) {
    if(index > vehicleRepository.size() or index < 0)
        throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleNoExist);
    auto it = std::next(vehicleRepository.begin(), index - 1);
    return *it;
}

bool VehicleRepository::find(shared_ptr<Vehicle> &ptr) {
    PredicateTemplate<VehiclePtr> find(ptr);
    auto wynik = std::find_if(vehicleRepository.begin(), vehicleRepository.end(), find);
    return wynik != vehicleRepository.end();
}
