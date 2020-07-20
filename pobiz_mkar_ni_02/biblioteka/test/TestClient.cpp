//
// Created by student on 24.04.2020.
//

#include <boost/test/unit_test.hpp>
#include <model/Address.h>
#include <model/Client.h>
#include "model/clientPremium.h"
#include "model/clientRegular.h"

BOOST_AUTO_TEST_SUITE(ClientSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientNamesAndIdCase){

        Client klient(std::make_shared<Address>("ulica", "21"),std::make_shared<Address>("ul", "32"),
                      "Jan","Kowalski","76102114514");

        BOOST_REQUIRE_EQUAL(klient.getPersonalId(), "76102114514");
        BOOST_REQUIRE_EQUAL(klient.getFirstName(), "Jan");
        BOOST_REQUIRE_EQUAL(klient.getLastName(), "Kowalski");
}

    BOOST_AUTO_TEST_CASE(ClientAddressCase){

        ClientPtr klient = std::make_shared<Client>(std::make_shared<Address>("ulica", "21"),
                std::make_shared<Address>("ul", "32"),"Mateo","Jakis","1212");
        BOOST_REQUIRE_EQUAL(klient->getAddress()->getAddressInfo(), "ulica 21");
        BOOST_REQUIRE_EQUAL(klient->getRegisterAddress()->getAddressInfo(), "ul 32");
}

    BOOST_AUTO_TEST_CASE(ClientTypeCase){

        ClientPtr klient = std::make_shared<Client>(std::make_shared<Address>("ulica", "21"),
                                                    std::make_shared<Address>("ul", "32"),"Mateo","Jakis","1212");
        ClientTypePtr type(new clientPremium());
        klient->setClientType(type);
        BOOST_REQUIRE_EQUAL(klient->getType()->getClientType(), "Premium");
        BOOST_REQUIRE_EQUAL(klient->getType()->discount(), 0.75f);
        BOOST_REQUIRE_EQUAL(klient->getType()->maxCars(), 8);
        ClientTypePtr type2(new clientRegular());
        klient->setClientType(type2);
        BOOST_REQUIRE_EQUAL(klient->getType()->getClientType(), "Regular");
        BOOST_REQUIRE_EQUAL(klient->getType()->discount(), 0.85f);
        BOOST_REQUIRE_EQUAL(klient->getType()->maxCars(), 4);
}


BOOST_AUTO_TEST_SUITE_END()