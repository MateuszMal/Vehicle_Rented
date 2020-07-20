//
// Created by student on 24.04.2020.
//

#include <boost/test/unit_test.hpp>
#include "model/Bicycle.h"

BOOST_AUTO_TEST_SUITE(BicycleSuiteCorrect)

    BOOST_AUTO_TEST_CASE(BicycleCase){

    Bicycle rower("Kolarka", 25);

    BOOST_REQUIRE_EQUAL(rower.getId(), "Kolarka");
    BOOST_REQUIRE_EQUAL(rower.getBaseRentPrice(), 25);
    BOOST_REQUIRE_EQUAL(rower.vehicleInfo(), "Kolarka: 25");
}

BOOST_AUTO_TEST_SUITE_END()