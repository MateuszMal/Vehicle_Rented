//
// Created by student on 23.04.2020.
//

#include "model/RentsRepository.h"
#include "model/Rent.h"
#include "model/RentsManager.h"
#include "model/PredicateTemplate.h"
#include "model/RentsRepositoryException.hpp"

RentsRepository::RentsRepository(){}

void RentsRepository::create(RentPtr &rent) {
    if(rent == nullptr) throw RentsRepositoryException(RentsRepositoryException::exceptionRentNullPtr);
    currentRents.push_back(rent);
}

void RentsRepository::remove(RentPtr &rent) {
    if(rent == nullptr) throw RentsRepositoryException(RentsRepositoryException::exceptionRentNullPtr);
    archiveRents.push_back(rent);
    currentRents.remove(rent);
}

void RentsRepository::rentReport() {
    std::list<RentPtr>::iterator it;
    for(it=currentRents.begin();
        it!=currentRents.end();
        ++it){
        (*it)->rentInfo();
    }
}

const list<RentPtr> &RentsRepository::getCurrentRents() const {
    return currentRents;
}

const list<RentPtr> &RentsRepository:: getArchiveRents() const {
    return archiveRents;
}

void RentsRepository::remove(int index) {
    if(index > currentRents.size() or index < 0)
        throw RentsRepositoryException(RentsRepositoryException::exceptionRentNoExist);
    auto it = std::next(currentRents.begin(), index);
    archiveRents.push_back(*it);
    currentRents.erase(it);
}

std::string RentsRepository::getAll() {
    for(auto & r : currentRents){
        r->rentInfo();
    }
}

shared_ptr<Rent> RentsRepository::find(int index) {
    if(index > currentRents.size() or index < 0)
        throw RentsRepositoryException(RentsRepositoryException::exceptionRentNoExist);
    auto it = std::next(currentRents.begin(), index - 1);
    return *it;
}

bool RentsRepository::find(shared_ptr<Rent> &ptr) {
    PredicateTemplate<RentPtr> find(ptr);
    auto wynik = std::find_if(currentRents.begin(), currentRents.end(), find);
    return wynik != currentRents.end();
}

RentsRepository::~RentsRepository() {}

