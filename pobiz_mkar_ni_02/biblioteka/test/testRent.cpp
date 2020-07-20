//
// Created by student on 16.04.2020.
//
#include <boost/test/unit_test.hpp>
#include "model/Vehicle.h"
#include "./model/Rent.h"
#include "model/Bicycle.h"


BOOST_AUTO_TEST_SUITE(RentSuiteCorrect)

    BOOST_AUTO_TEST_CASE(RentCase) {

        ClientPtr klient = std::make_shared<Client>(std::make_shared<Address>("ulica", "21"),
                                                    std::make_shared<Address>("ul", "32"), "Mateo", "Jakis", "1212");
        VehiclePtr pojazd = make_shared<Bicycle>("Romet", 35);
        ptime jakas_data(date(2020, Apr, 5), hours(10));
        RentPtr wypo = make_shared<Rent>(std::shared_ptr<Client>(klient), std::shared_ptr<Vehicle>(pojazd));
        wypo->addClientRent();
        BOOST_CHECK(klient->totalRents() > 0);
    }

    BOOST_AUTO_TEST_CASE(RentEndRentCase) {
        ClientPtr klient = std::make_shared<Client>(std::make_shared<Address>("ulica", "21"),
                                                    std::make_shared<Address>("ul", "32"), "Mateo", "Jakis", "1212");
        VehiclePtr pojazd = make_shared<Bicycle>("Kross", 35);
        ptime jakas_data(date(2020, Apr, 5), hours(10));
        RentPtr wypo = make_shared<Rent>(std::shared_ptr<Client>(klient), std::shared_ptr<Vehicle>(pojazd));
        wypo->addClientRent();
        BOOST_CHECK(klient->totalRents() > 0);
        wypo->endRent();
        BOOST_CHECK(klient->totalRents() == 0);
    }

    BOOST_AUTO_TEST_CASE(RentGetPriceCase){

        ClientPtr klient = std::make_shared<Client>(std::make_shared<Address>("ulica", "21"),
                                                    std::make_shared<Address>("ul", "32"), "Mateo", "Jakis", "1212");
        VehiclePtr pojazd = make_shared<Bicycle>("Kross", 35);
        ptime jakas_data(date(2020, Apr, 5), hours(10));
        RentPtr wypo = make_shared<Rent>(std::shared_ptr<Client>(klient), std::shared_ptr<Vehicle>(pojazd));;
        wypo->addClientRent();
        wypo->endRent();
        BOOST_REQUIRE_EQUAL(wypo->getPrice(), 35);
    }

BOOST_AUTO_TEST_SUITE_END()
