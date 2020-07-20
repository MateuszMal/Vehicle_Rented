//
// Created by student on 14.05.2020.
//

#ifndef MAL_LAT_RENTSMANAGER_H
#define MAL_LAT_RENTSMANAGER_H

#include <memory>
#include <list>
#include <vector>
#include "model/clientRegular.h"
#include "model/clientStandard.h"
#include "model/clientPremium.h"

using namespace std;
class Rent;
class Client;
class Vehicle;
class ClientRepository;
class RentsRepository;
typedef shared_ptr<Rent> RentPtr ;
typedef shared_ptr<Client> ClientPtr ;
typedef shared_ptr<Vehicle> VehiclePtr ;
typedef shared_ptr<ClientRepository> ClientRepositoryPtr;
typedef shared_ptr<RentsRepository> RentsRepositoryPtr;

class RentsManager{
private:
    RentsRepositoryPtr currentRepository;
    RentsRepositoryPtr archiveRepository;
    ClientRepositoryPtr clientRepository;
public:
    RentsManager();
    std::list<RentPtr> getAllClientRents(ClientPtr klient);
    std::list<RentPtr> getCurrentClientRents(ClientPtr klient);
    void rentVehicle(RentPtr rent);
    void returnVehicle(RentPtr rent);
    int checkClientRentBallance(ClientPtr klient);
    void changeClientType(ClientPtr klient);
};

typedef shared_ptr<RentsManager> RentsManagerPtr;
#endif //MAL_LAT_RENTSMANAGER_H
