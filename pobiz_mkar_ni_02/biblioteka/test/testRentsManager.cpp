#include <boost/test/unit_test.hpp>
#include <model/Car.h>
#include <model/RentsManager.h>
#include "model/Rent.h"
#include "model/Vehicle.h"
#include "model/Bicycle.h"
#include "model/Moped.h"
#include "model/Client.h"


BOOST_AUTO_TEST_SUITE(RentsManagerSuiteCorrect)

    BOOST_AUTO_TEST_CASE(RentsManagerRentVehicleCase){
        ClientPtr klient = std::make_shared<Client>(std::make_shared<Address>("ulica", "21"),
                                                    std::make_shared<Address>("ul","23"),
                                                    "Jan","Kowalski","66101323255");
        VehiclePtr pojazd= std::make_shared<Car>("EBE 21345", 50, 1900, "B");
        RentPtr wypo = std::make_shared<Rent>(klient, pojazd);
        RentsManagerPtr manager(new RentsManager());
        manager->rentVehicle(wypo);
        BOOST_REQUIRE_EQUAL(manager->getCurrentClientRents(klient).size(), 1);
}

    BOOST_AUTO_TEST_CASE(RentsManagerReturnVehicleCase) {
        ClientPtr klient = std::make_shared<Client>(std::make_shared<Address>("ulica", "21"),
                                                    std::make_shared<Address>("ul", "23"),
                                                    "Jan", "Kowalski", "66101323255");
        VehiclePtr pojazd = std::make_shared<Car>("EBE 21345", 50, 1900, "B");
        RentPtr wypo = std::make_shared<Rent>(klient, pojazd);
        RentsManagerPtr manager(new RentsManager());
        manager->rentVehicle(wypo);
        manager->returnVehicle(wypo);
        BOOST_REQUIRE_EQUAL(manager->getCurrentClientRents(klient).size(), 0);
        BOOST_REQUIRE_EQUAL(manager->getAllClientRents(klient).size(), 1);
    }

    BOOST_AUTO_TEST_CASE(RentsManagerChangeclientBalanceCase){
        ClientPtr klient = std::make_shared<Client>(std::make_shared<Address>("ulica", "21"),
                                                    std::make_shared<Address>("ul", "23"),
                                                    "Jan", "Kowalski", "66101323255");
        VehiclePtr pojazd = std::make_shared<Car>("EBE 21345", 50, 1900, "B");
        VehiclePtr rower = std::make_shared<Bicycle>("Kross", 23);
        VehiclePtr moped = std::make_shared<Moped>("Romet",23,110);
        RentPtr wypo = std::make_shared<Rent>(klient, pojazd);
        wypo->addClientRent();
        RentPtr wypo2 = std::make_shared<Rent>(klient, rower);
        wypo2->addClientRent();
        RentPtr wypo3 = std::make_shared<Rent>(klient, moped);
        wypo3->addClientRent();
        RentsManagerPtr manager(new RentsManager());
        manager->rentVehicle(wypo);
        manager->rentVehicle(wypo2);
        manager->rentVehicle(wypo3);
        BOOST_REQUIRE_EQUAL(manager->checkClientRentBallance(klient), 3);
        manager->returnVehicle(wypo3);
        BOOST_REQUIRE_EQUAL(klient->getType()->getClientType(), "Regular");
}

BOOST_AUTO_TEST_SUITE_END()




