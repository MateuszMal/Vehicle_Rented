//
// Created by student on 31.05.2020.
//

#ifndef MAL_LAT_CLIENTMANAGER_H
#define MAL_LAT_CLIENTMANAGER_H

#include <memory>

class ClientRepository;
class Client;

typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<ClientRepository> ClientRepositoryPtr;

class ClientManager{
private:
    ClientRepositoryPtr currentRepository;
    ClientRepositoryPtr archiveRepository;

public:
    ClientManager();
    void addClient(ClientPtr klient);
    void removeClient(ClientPtr klient);
    void removeClient(int index);
    int numberOfCurrentClients();
    int numberOfArchiveClients();
    virtual ~ClientManager();
};

typedef std::shared_ptr<ClientManager> ClientManagerPtr;

#endif //MAL_LAT_CLIENTMANAGER_H
