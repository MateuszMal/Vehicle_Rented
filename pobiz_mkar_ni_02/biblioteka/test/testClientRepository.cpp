#include <boost/test/unit_test.hpp>
#include <model/clientRegular.h>
#include <model/clientPremium.h>
#include "./model/ClientRepository.h"
#include "./model/Client.h"


BOOST_AUTO_TEST_SUITE(ClientRepositorySuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientRepositoryClrateCase){

    ClientPtr klient = std::make_shared<Client>(std::make_shared<Address>("ulica", "21"),
            std::make_shared<Address>("ul","23"),"Jan","Kowalski","66101323255");
    ClientRepository repo;
    repo.create(klient);
    BOOST_REQUIRE_EQUAL(repo.howManyClients(), 1);
}

    BOOST_AUTO_TEST_CASE(ClientRepositoryRemovePtrClientCase){

        ClientPtr klient = std::make_shared<Client>(std::make_shared<Address>("ulica", "21"),
                                                    std::make_shared<Address>("ul","23"),
                                                    "Jan","Kowalski","66101323255");
        ClientRepository repo;
        repo.create(klient);
        repo.remove(klient);
        BOOST_REQUIRE_EQUAL(repo.howManyClients(), 0);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryRemoveIntClientCase){

        ClientPtr klient = std::make_shared<Client>(std::make_shared<Address>("ulica", "21"),
                                                    std::make_shared<Address>("ul","23"),
                                                    "Jan","Kowalski","66101323255");
        ClientPtr klient1 = std::make_shared<Client>(std::make_shared<Address>("ulica", "21"),
                                                    std::make_shared<Address>("ul","23"),
                                                    "Jan","Nowak","6610133323255");
        ClientRepository repo;
        repo.create(klient);
        repo.create(klient1);
        BOOST_REQUIRE_EQUAL(repo.howManyClients(), 2);
        repo.remove(1);
        BOOST_REQUIRE_EQUAL(repo.howManyClients(), 1);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryChangeTypeClientCase){

        ClientPtr klient = std::make_shared<Client>(std::make_shared<Address>("ulica", "21"),
                                                    std::make_shared<Address>("ul","23"),
                                                    "Jan","Kowalski","66101323255");
        ClientTypePtr type(new clientRegular());
        ClientRepository repo;
        repo.create(klient);
        repo.changeType(klient, type);
        BOOST_REQUIRE_EQUAL(repo.getAll(), "JanKowalskiRegular");
        ClientTypePtr type2(new clientPremium());
        repo.changeType(klient, type2);
        BOOST_REQUIRE_EQUAL(repo.getAll(), "JanKowalskiPremium");
    }

BOOST_AUTO_TEST_SUITE_END()