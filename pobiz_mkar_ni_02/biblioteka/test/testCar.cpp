//
// Created by student on 24.04.2020.
//

#include <boost/test/unit_test.hpp>
#include <iostream>
#include "model/Car.h"

BOOST_AUTO_TEST_SUITE(CarSuiteCorrect)

    BOOST_AUTO_TEST_CASE(CarCase){

        Car dacia("Logan", 100, 1500, "E");
        BOOST_REQUIRE_EQUAL(dacia.getId(), "Logan");
        BOOST_REQUIRE_EQUAL(dacia.getBaseRentPrice(), 150);
        BOOST_REQUIRE_EQUAL(dacia.getEngineDisplacement(), 1500);
        BOOST_REQUIRE_EQUAL(dacia.getSegment(), "E");
        BOOST_REQUIRE_EQUAL(dacia.vehicleInfo(), "\nNazwa: Logan\nSegment: E\nPojemnosc: 1500.000000\nCena bazowa: 150");

}

BOOST_AUTO_TEST_SUITE_END()