#include "model/RentsManager.h"
#include "model/RentsRepository.h"
#include "model/ClientRepository.h"
#include "model/RentsManagerException.h"
#include "model/ClientException.h"


RentsManager::RentsManager() : currentRepository(new RentsRepository),
                                archiveRepository(new RentsRepository) {}

void RentsManager::rentVehicle(RentPtr rent){

    for(auto & r : currentRepository->getCurrentRents()){
        if(r == rent)throw RentsManagerException(RentsManagerException::exceptionRentsManagerVehicleIsRented);
    }
    if(rent == nullptr)throw RentsManagerException(RentsManagerException::exceptionRentsManagerNullPtr);
    currentRepository->create(rent);
}

void RentsManager::returnVehicle(RentPtr rent) {
    if (rent == nullptr)throw RentsManagerException(RentsManagerException::exceptionRentsManagerNullPtr);
    bool flag = false;
    for (auto &r : currentRepository->getCurrentRents()) {
        if (rent == r) {
            flag = true;
            currentRepository->remove(rent);
            archiveRepository->create(rent);
            rent->getClient()->removeRent(rent);
            changeClientType(rent->getClient());
            rent->endRent();
            break;
        }
    }
    if(flag == false) throw RentsManagerException(RentsManagerException::exceptionRentsManagerNoExist);
}

std::list<RentPtr> RentsManager::getAllClientRents(ClientPtr klient){
    if(klient == nullptr)throw ClientException(ClientException::exceptionNullPtr);
    return archiveRepository->getCurrentRents();
}

std::list<RentPtr> RentsManager::getCurrentClientRents(ClientPtr klient) {
    if(klient == nullptr)throw ClientException(ClientException::exceptionNullPtr);
    return currentRepository->getCurrentRents();
}

void RentsManager::changeClientType(ClientPtr klient) {
    if(klient == nullptr)throw ClientException(ClientException::exceptionNullPtr);
    if(checkClientRentBallance(klient) >= 2 and checkClientRentBallance(klient) < 4){
        ClientTypePtr newType = std::make_shared<clientRegular>();
        clientRepository->changeType(klient, newType);
    }
    if(checkClientRentBallance(klient) >= 4){
        ClientTypePtr newType = std::make_shared<clientPremium>();
        clientRepository->changeType(klient, newType);
    }
}

int RentsManager::checkClientRentBallance(ClientPtr klient){
    if(klient == nullptr)throw ClientException(ClientException::exceptionNullPtr);
    return klient->getClientBalance();
}