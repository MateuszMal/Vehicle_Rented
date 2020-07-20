//
// Created by student on 24.04.2020.
//

#include <boost/test/unit_test.hpp>

#include "model/Moped.h"

BOOST_AUTO_TEST_SUITE(MopedSuiteCorrect)

    BOOST_AUTO_TEST_CASE(MopedCase){
    Moped skuter("Romet", 50, 750);

    BOOST_REQUIRE_EQUAL(skuter.getId(), "Romet");
    BOOST_REQUIRE_EQUAL(skuter.getBaseRentPrice(), 50);
    BOOST_REQUIRE_EQUAL(skuter.getEngineDisplacement(), 750);
    BOOST_REQUIRE_EQUAL(skuter.vehicleInfo(), "\nNazwa: Romet\nPojemnosc: 750.000000\nCena bazowa: 50");

}

BOOST_AUTO_TEST_SUITE_END()