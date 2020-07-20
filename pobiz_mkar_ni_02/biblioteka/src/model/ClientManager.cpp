//
// Created by student on 31.05.2020.
//

#include "model/ClientManager.h"
#include "model/ClientRepository.h"
#include "model/Client.h"
#include "model/ClientManagerExceptions.h"

ClientManager::ClientManager() : currentRepository(new ClientRepository),
                                archiveRepository(new ClientRepository) {}

ClientManager::~ClientManager() {}

void ClientManager::addClient(ClientPtr klient) {
    if(klient == nullptr) throw ClientManagerExceptions(ClientManagerExceptions::exceptionClientManagerNullPtr);
    for(const auto & cl : currentRepository->getAllClients()){
        if(klient == cl) throw ClientManagerExceptions(ClientManagerExceptions::exceptionClientManagerClientIsExist);
    }
    currentRepository->create(klient);
}

void ClientManager::removeClient(ClientPtr klient) {
    if(klient == nullptr) throw ClientManagerExceptions(ClientManagerExceptions::exceptionClientManagerNullPtr);
    bool flag = false;
    for(const auto & cl : currentRepository->getAllClients()) {
        if (klient == cl) {
            flag = true;
            currentRepository->remove(klient);
            archiveRepository->create(klient);
            break;
        }
    }
    if(flag == false) throw ClientManagerExceptions(ClientManagerExceptions::exceptionClientManagerNoExist);

}

void ClientManager::removeClient(int index) {
    if(index > currentRepository->getAllClients().size() or index < 0)
        throw ClientManagerExceptions(ClientManagerExceptions::exceptionClientManagerNoExist);
    currentRepository->remove(index);
}

int ClientManager::numberOfCurrentClients() {
    return currentRepository->getAllClients().size();
}

int ClientManager::numberOfArchiveClients() {
    return archiveRepository->getAllClients().size();
}




