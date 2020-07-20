//
// Created by student on 14.05.2020.
//

#include "model/Client.h"
#include "model/ClientRepository.h"
#include "model/RentsManager.h"
#include "model/PredicateTemplate.h"
#include "model/ClientRepositoryException.hpp"
#include <algorithm>

void ClientRepository::create(ClientPtr &client) {
    if(client == nullptr) throw ClientReposiroryException(ClientReposiroryException::exceptionClientPtrNullPtr);
    allClients.push_back(client);
}

void ClientRepository::remove(ClientPtr &client) {
    if(client == nullptr) throw ClientReposiroryException(ClientReposiroryException::exceptionClientPtrNullPtr);
    allClients.remove(client);
}

void ClientRepository::remove(int nr) {
    auto it = std::next(allClients.begin(), nr);
    allClients.erase(it);
}

void ClientRepository::changeType(ClientPtr klient, ClientTypePtr typKlienta) {
    if(klient == nullptr) throw ClientReposiroryException(ClientReposiroryException::exceptionClientPtrNullPtr);
    klient->setClientType(typKlienta);
}

std::string ClientRepository::getAll() {
    for(const auto& klient : allClients){
        return klient->getFirstName() + klient->getLastName() + klient->getType()->getClientType();
    }
}

int ClientRepository::howManyClients() {
    return allClients.size();
}

const list<ClientPtr> &ClientRepository::getAllClients() const {
    return allClients;
}

shared_ptr<Client> ClientRepository::find(int index) {
    if(index > allClients.size() or index < 0)
        throw ClientReposiroryException(ClientReposiroryException::exceptionNoClient);
    auto it = std::next(allClients.begin(), index - 1);
    return *it;
}

bool ClientRepository::find(shared_ptr<Client> &ptr) {
    if(ptr == nullptr) throw ClientReposiroryException(ClientReposiroryException::exceptionClientPtrNullPtr);
    PredicateTemplate<ClientPtr> find(ptr);
    auto wynik = std::find_if(allClients.begin(), allClients.end(), find);
    return wynik != allClients.end();
}
