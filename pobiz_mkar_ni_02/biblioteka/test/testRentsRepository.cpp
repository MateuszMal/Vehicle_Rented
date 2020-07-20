#include <boost/test/unit_test.hpp>

#include "model/Rent.h"
#include "model/Client.h"
#include "model/RentsRepository.h"
#include "model/Bicycle.h"
#include <string>
#include "model/RentsManager.h"
#include <memory>

using namespace std;

BOOST_AUTO_TEST_SUITE(RentsRepositorySuiteCorrect)

    BOOST_AUTO_TEST_CASE(RentsRepositoryCreate) {

        VehiclePtr bicycle = make_shared<Bicycle>("HFNJD2342356", 100);
        ClientPtr client = make_shared<Client>(make_shared<Address>("ulica", "21"), make_shared<Address>("ul", "32"),
                                                "Jan", "Kowalski", "76102114514");
        RentPtr rent = make_shared<Rent>(client, bicycle);
        RentsRepositoryPtr repo(new RentsRepository);
        repo->create(rent);
        BOOST_REQUIRE_EQUAL(repo->getCurrentRents().size(), 1);
    }

    BOOST_AUTO_TEST_CASE(RentsRepositoryRemoveByPtr) {

        VehiclePtr bicycle = make_shared<Bicycle>("HFNJhfadh42356", 100);
        ClientPtr client = make_shared<Client>(make_shared<Address>("ulica", "21"), make_shared<Address>("ul", "32"),
                                                "Jan", "Kowalski", "76102114514");
        RentPtr rent = make_shared<Rent>(client, bicycle);
        RentsRepositoryPtr repo(new RentsRepository);
        repo->create(rent);
        BOOST_REQUIRE_EQUAL(repo->getCurrentRents().size(), 1);
        repo->remove(rent);
        BOOST_REQUIRE_EQUAL(repo->getCurrentRents().size(), 0);
        BOOST_REQUIRE_EQUAL(repo->getArchiveRents().size(), 1);
    }

    BOOST_AUTO_TEST_CASE(RentsRepositoryRemoveByIndex) {

        VehiclePtr bicycle3 = make_shared<Bicycle>("HFNJD2ssd42356", 100);
        ClientPtr client3 = make_shared<Client>(make_shared<Address>("ulica", "21"), make_shared<Address>("ul", "32"),
                                                "Jan", "Kowalski", "76102114514");
        RentPtr rent3 = make_shared<Rent>(client3, bicycle3);
        RentsRepositoryPtr repo3(new RentsRepository);
        repo3->create(rent3);
        BOOST_REQUIRE_EQUAL(repo3->getCurrentRents().size(), 1);
        repo3->remove(0);
        BOOST_REQUIRE_EQUAL(repo3->getCurrentRents().size(), 0);
        BOOST_REQUIRE_EQUAL(repo3->getArchiveRents().size(), 1);
    }
    BOOST_AUTO_TEST_CASE(RentsRepositoryGetAll) {

        VehiclePtr bicycle = make_shared<Bicycle>("HFNJD23rtuhyd2356", 100);
        ClientPtr client = make_shared<Client>(make_shared<Address>("ulica", "21"), make_shared<Address>("ul", "32"),
                                               "Jan", "Kowalski", "76102114514");
        RentPtr rent = make_shared<Rent>(client, bicycle);
        RentsRepositoryPtr repo(new RentsRepository);
        repo->create(rent);
        BOOST_REQUIRE_EQUAL(repo->getCurrentRents().size(), 1);
        repo->getAll();
    }

    BOOST_AUTO_TEST_CASE(RentsRepositoryFindByIndex){

        VehiclePtr bicycle = make_shared<Bicycle>("HFNJD23rtuhyd2356", 100);
        ClientPtr client = make_shared<Client>(make_shared<Address>("ulica", "21"), make_shared<Address>("ul", "32"),
                                               "Jan", "Kowalski", "76102114514");
        RentPtr rent = make_shared<Rent>(client, bicycle);
        RentsRepositoryPtr repo(new RentsRepository);
        repo->create(rent);
        BOOST_REQUIRE_EQUAL(repo->getCurrentRents().size(), 1);
        BOOST_REQUIRE_EQUAL(repo->find(1), rent);
    }


    BOOST_AUTO_TEST_CASE(RentsRepositoryFindByPtr){

        VehiclePtr bicycle = make_shared<Bicycle>("HFNJD23rtuhyd2356", 100);
        ClientPtr client = make_shared<Client>(make_shared<Address>("ulica", "21"), make_shared<Address>("ul", "32"),
                                               "Jan", "Kowalski", "76102114514");
        RentPtr rent = make_shared<Rent>(client, bicycle);
        RentsRepositoryPtr repo(new RentsRepository);
        repo->create(rent);
        BOOST_REQUIRE_EQUAL(repo->getCurrentRents().size(), 1);
        BOOST_CHECK(repo->find(rent));
    }

BOOST_AUTO_TEST_SUITE_END()