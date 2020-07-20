//
// Created by student on 16.06.2020.
//

#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "model/Client.h"
#include "model/Car.h"
#include "model/Vehicle.h"
#include "model/Bicycle.h"
#include "model/Address.h"
#include "model/RentsRepository.h"
#include "model/ClientRepository.h"
#include "model/VehicleRepository.h"
#include "model/RentsManager.h"
#include "model/ClientManager.h"
#include "model/VehicleManager.h"

BOOST_AUTO_TEST_SUITE(TestExceptionSuiteCorect)

    BOOST_AUTO_TEST_CASE(ClientExceptionCase){
        AddressPtr adres = nullptr;
        AddressPtr adres1 = make_shared<Address>("Nowa","13");
        BOOST_REQUIRE_THROW(Client(adres, adres, "Jan", "Kowalski", "8934234234"), logic_error);
        BOOST_REQUIRE_THROW(Client(adres1, adres1, "", "Kowalski", "8934234234"), logic_error);
        BOOST_REQUIRE_THROW(Client(adres1, adres1, "Jan", "", "8934234234"), logic_error);
        BOOST_REQUIRE_THROW(Client(adres1, adres1, "Jan", "Kowalski", ""), logic_error);
}
    BOOST_AUTO_TEST_CASE(AddressExceptionCase){
        BOOST_REQUIRE_THROW(Address("", "13"), logic_error);
        BOOST_REQUIRE_THROW(Address("Nowa", ""), logic_error);
}
    BOOST_AUTO_TEST_CASE(VehicleExceptionCase){
        BOOST_REQUIRE_THROW(VehiclePtr(new Bicycle("", 25)), logic_error);
        BOOST_REQUIRE_THROW(VehiclePtr(new Bicycle("Pojazd", -25)), logic_error);
        BOOST_REQUIRE_THROW(Car("Pojazd", 25, -1200, "B"), logic_error);
        BOOST_REQUIRE_THROW(Car("Pojazd", 25, 1200, "G"), logic_error);
}
    BOOST_AUTO_TEST_CASE(ClientRepositoryCreateExceptionCase){
        AddressPtr adres1 = make_shared<Address>("Nowa","13");
        ClientPtr klient = nullptr;
        ClientPtr klient1(new Client(adres1,adres1, "Jan","Kowalski", "234234"));
        ClientRepository Repo;
        BOOST_REQUIRE_THROW(Repo.create(klient), logic_error);
}
    BOOST_AUTO_TEST_CASE(ClientRepositoryRemoveExceptionCase){
        AddressPtr adres1 = make_shared<Address>("Nowa","13");
        ClientPtr klient = nullptr;
        ClientPtr klient1(new Client(adres1,adres1, "Jan","Kowalski", "234234"));
        ClientRepository Repo;
        BOOST_REQUIRE_THROW(Repo.remove(klient), logic_error);
//        BOOST_REQUIRE_THROW(Repo.remove(klient1), logic_error);
//        Repo.create(klient1);
//        BOOST_REQUIRE_THROW(Repo.remove(2), logic_error);
}
    BOOST_AUTO_TEST_CASE(ClientRepositoryChangeTypeExceptionCase){
        ClientPtr klient = nullptr;
        ClientTypePtr type(new clientPremium());
        ClientRepository Repo;
        BOOST_REQUIRE_THROW(Repo.changeType(klient, type), logic_error);
}
    BOOST_AUTO_TEST_CASE(VehicleRepositoryCreateCase){
        VehiclePtr pojazd(new Car("EL 12343",57,1200,"C"));
        VehiclePtr pojazd2 = nullptr;
        VehicleRepository Repo;
        BOOST_REQUIRE_THROW(Repo.create(pojazd2), logic_error);
//        Repo.create(pojazd);
//        BOOST_REQUIRE_THROW(Repo.create(pojazd), logic_error);
}
    BOOST_AUTO_TEST_CASE(VehicleRepositoryRemoveCase){
        VehiclePtr pojazd(new Car("EL 12343",57,1200,"C"));
        VehiclePtr pojazd2 = nullptr;
        VehicleRepository Repo;
        BOOST_REQUIRE_THROW(Repo.remove(pojazd2), logic_error);
//        Repo.create(pojazd);
//        BOOST_REQUIRE_THROW(Repo.remove(2), logic_error);
}
    BOOST_AUTO_TEST_CASE(RentsRepositoryCreateExceptionCase){
        ClientPtr klient = std::make_shared<Client>(std::make_shared<Address>("ulica", "21"),
                                                    std::make_shared<Address>("ul","23"),
                                                    "Jan","Kowalski","66101323255");
        VehiclePtr pojazd= std::make_shared<Car>("EBE 21345", 50, 1900, "B");
        RentPtr wypo = std::make_shared<Rent>(klient, pojazd);
        RentPtr wypo2 = nullptr;
        RentsRepository Repo;
        BOOST_REQUIRE_THROW(Repo.create(wypo2), logic_error);
        Repo.create(wypo);
}
    BOOST_AUTO_TEST_CASE(RentsRepositoryRemoveExceptionCase){
        ClientPtr klient = std::make_shared<Client>(std::make_shared<Address>("ulica", "21"),
                                                    std::make_shared<Address>("ul","23"),
                                                    "Jan","Kowalski","66101323255");
        VehiclePtr pojazd= std::make_shared<Car>("EBE 21345", 50, 1900, "B");
        RentPtr wypo = std::make_shared<Rent>(klient, pojazd);
        RentPtr wypo2 = nullptr;
        RentsRepository Repo;
        BOOST_REQUIRE_THROW(Repo.remove(wypo2), logic_error);
        BOOST_REQUIRE_THROW(Repo.remove(2), logic_error);
}
    BOOST_AUTO_TEST_CASE(RentsManagerRentVehicleExceptionCase){
        ClientPtr klient = std::make_shared<Client>(std::make_shared<Address>("ulica", "21"),
                                                    std::make_shared<Address>("ul","23"),
                                                    "Jan","Kowalski","66101323255");
        VehiclePtr pojazd= std::make_shared<Car>("EBE 21345", 50, 1900, "B");
        RentPtr wypo = std::make_shared<Rent>(klient, pojazd);
        RentsManagerPtr manager(new RentsManager());
        manager->rentVehicle(wypo);
        RentPtr wypo2 = nullptr;
        BOOST_REQUIRE_THROW(manager->rentVehicle(wypo2), logic_error); // nullptr!
        BOOST_REQUIRE_THROW(manager->rentVehicle(wypo), logic_error); // drugi raz to samo wypozyczenie
}
    BOOST_AUTO_TEST_CASE(RentsManagerReturnVehicleExceptionCase){
        ClientPtr klient = std::make_shared<Client>(std::make_shared<Address>("ulica", "21"),
                                                    std::make_shared<Address>("ul","23"),
                                                    "Jan","Kowalski","66101323255");
        VehiclePtr pojazd= std::make_shared<Car>("EBE 21345", 50, 1900, "B");
        RentPtr wypo = std::make_shared<Rent>(klient, pojazd);
        RentPtr wypo2 = nullptr;
        RentsManagerPtr manager(new RentsManager());
        BOOST_REQUIRE_THROW(manager->returnVehicle(wypo2), logic_error); // nullptr!
        BOOST_REQUIRE_THROW(manager->returnVehicle(wypo), logic_error); // wypozyczenie nie dodane do managera
}

    BOOST_AUTO_TEST_CASE(ClientManagerAddClientCase){
        ClientPtr klient = std::make_shared<Client>(std::make_shared<Address>("ulica", "21"),
                                                    std::make_shared<Address>("ul","23"),
                                                    "Jan","Kowalski","66101323255");
        ClientPtr klient2 = nullptr;
        ClientManagerPtr manager(new ClientManager());
        BOOST_REQUIRE_THROW(manager->addClient(klient2), logic_error);
        manager->addClient(klient);
        BOOST_REQUIRE_THROW(manager->addClient(klient), logic_error);
}

    BOOST_AUTO_TEST_CASE(ClientManagerRemoveClientCase) {
        ClientPtr klient = std::make_shared<Client>(std::make_shared<Address>("ulica", "21"),
                                                    std::make_shared<Address>("ul", "23"),
                                                    "Jan", "Kowalski", "66101323255");
        ClientPtr klient2 = nullptr;
        ClientManagerPtr manager(new ClientManager());
        BOOST_REQUIRE_THROW(manager->removeClient(klient), logic_error); // klient nie istnieje w Rrepozytorium
        BOOST_REQUIRE_THROW(manager->removeClient(klient2), logic_error); // nullptr
        BOOST_REQUIRE_THROW(manager->removeClient(4), logic_error); // index poza zakresem
}

    BOOST_AUTO_TEST_CASE(VehicleManagerAddVehicleCase){
        VehiclePtr pojazd = std::make_shared<Car>("EBE 21345", 50, 1900, "B");
        VehiclePtr pojazd2 = nullptr;
        VehicleManagerPtr manager(new VehicleManager());
        BOOST_REQUIRE_THROW(manager->addVehicle(pojazd2), logic_error); // nullptr
        manager->addVehicle(pojazd);
        BOOST_REQUIRE_THROW(manager->addVehicle(pojazd), logic_error); // drugi raz ten sam pojazd w repo
    }

    BOOST_AUTO_TEST_CASE(VehicleManagerRemoveVehicleCase){
        VehiclePtr pojazd = std::make_shared<Car>("EBE 21345", 50, 1900, "B");
        VehiclePtr pojazd2 = nullptr;
        VehicleManagerPtr manager(new VehicleManager());
        BOOST_REQUIRE_THROW(manager->removeVehicle(pojazd2), logic_error); // nullptr
        BOOST_REQUIRE_THROW(manager->removeVehicle(pojazd), logic_error); // brak pojazdu w repo
        BOOST_REQUIRE_THROW(manager->removeVehicle(5), logic_error); // index poza zakresem
}


BOOST_AUTO_TEST_SUITE_END()