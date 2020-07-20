//
// Created by student on 24.04.2020.
//

#include <boost/test/unit_test.hpp>
#include "model/Bicycle.h"
#include <model/Vehicle.h>

BOOST_AUTO_TEST_SUITE(VehicleSuiteCorrect)

    BOOST_AUTO_TEST_CASE(VehicleCase){

    VehiclePtr pojazd(new Bicycle("Fiat", 212));

    BOOST_REQUIRE_EQUAL(pojazd->getId(), "Fiat");
    BOOST_REQUIRE_EQUAL(pojazd->getBaseRentPrice(), 212);
    BOOST_REQUIRE_EQUAL(pojazd->vehicleInfo(), "Fiat: 212");
}

BOOST_AUTO_TEST_SUITE_END()