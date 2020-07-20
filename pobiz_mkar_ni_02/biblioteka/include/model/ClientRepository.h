//
// Created by student on 14.05.2020.
//

#ifndef MAL_LAT_CLIENTREPOSITORY_H
#define MAL_LAT_CLIENTREPOSITORY_H

#include <list>
#include "ClientType.h"
#include "model/Repository.h"
#include <string>

using namespace std;

class Client;

typedef std::shared_ptr<Client> ClientPtr;

class ClientRepository : public Repository<Client> {
private:
    friend class RentsManager;
    list<ClientPtr> allClients{};
public:
    void create(ClientPtr&) override ;
    void remove(ClientPtr&) override ;
    void remove(int) override ;
    void changeType(ClientPtr klient, ClientTypePtr);
    std::string getAll();
    int howManyClients();
    shared_ptr<Client> find(int index) override;
    bool find(shared_ptr<Client> &ptr) override;
    const list<ClientPtr> &getAllClients() const;
};

typedef std::shared_ptr<ClientRepository> ClientRepositoryPtr;
#endif //MAL_LAT_CLIENTREPOSITORY_H
