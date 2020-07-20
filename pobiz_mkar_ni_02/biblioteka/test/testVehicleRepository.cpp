//
// Created by student on 14.05.2020.
//

#include <boost/test/unit_test.hpp>
#include <model/VehicleRepository.h>
#include <string>
#include <memory>
#include <model/Bicycle.h>
#include <model/Moped.h>
#include <model/Car.h>


BOOST_AUTO_TEST_SUITE(VehicleRepositorySuiteCorrect)

    BOOST_AUTO_TEST_CASE(VehicleRepositoryCreateCase){
    VehiclePtr pojazd = make_shared<Bicycle>("Rower",11.233);
    VehicleRepositoryPtr repo(new VehicleRepository);
    repo->create(pojazd);
    BOOST_REQUIRE_EQUAL(repo->getVehicleRepository().size(), 1);
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryRemoveByPtrCase) {
        VehiclePtr pojazd = make_shared<Bicycle>("Rower", 25);
        VehicleRepositoryPtr repo(new VehicleRepository);
        repo->create(pojazd);
        BOOST_REQUIRE_EQUAL(repo->getVehicleRepository().size(), 1);
        repo->remove(pojazd);
        BOOST_REQUIRE_EQUAL(repo->getVehicleRepository().size(), 0);
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryRemoveByIndexCase) {
        VehiclePtr pojazd = make_shared<Bicycle>("Rower", 25);
        VehicleRepositoryPtr repo(new VehicleRepository);
        repo->create(pojazd);
        BOOST_REQUIRE_EQUAL(repo->getVehicleRepository().size(), 1);
        repo->remove(0);
        BOOST_REQUIRE_EQUAL(repo->getVehicleRepository().size(), 0);
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryFindByIndexCase) {
        VehiclePtr pojazd = make_shared<Bicycle>("Rower", 25);
        VehicleRepositoryPtr repo(new VehicleRepository);
        repo->create(pojazd);
        BOOST_REQUIRE_EQUAL(repo->getVehicleRepository().size(), 1);
        BOOST_REQUIRE_EQUAL(repo->find(1), pojazd);
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryFindByPtrCase) {
        VehiclePtr pojazd = make_shared<Bicycle>("Rower", 25);
        VehicleRepositoryPtr repo(new VehicleRepository);
        repo->create(pojazd);
        BOOST_REQUIRE_EQUAL(repo->getVehicleRepository().size(), 1);
        BOOST_CHECK(repo->find(pojazd));
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryRaportCase){
    VehiclePtr tab[10];
    tab[0] = make_shared<Bicycle>("Kross",50);
    tab[1] = make_shared<Bicycle>("Nowy", 35);
    tab[2] = make_shared<Car>("Peugeot",150,1200,"D");
    tab[3] = make_shared<Car>("Polonez",110,1500,"E");
    tab[4] = make_shared<Car>("Lada",80,1600,"A");
    tab[5] = make_shared<Car>("Skoda",100,1400,"B");
    tab[6] = make_shared<Moped>("Romet",75,110);
    tab[7] = make_shared<Moped>("Kawasaki",120,750);
    tab[8] = make_shared<Moped>("Suzuki",110,500);
    tab[9] = make_shared<Moped>("Honda",120,750);

    VehicleRepository repozytorium;
    for(int i=0; i<10; ++i){
        repozytorium.create(tab[i]);
    };
    repozytorium.vehicleRaport();
    }

BOOST_AUTO_TEST_SUITE_END()