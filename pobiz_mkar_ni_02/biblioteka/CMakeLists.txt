cmake_minimum_required(VERSION 3.4)
project(Biblioteka)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/model/Client.cpp include/model/Client.h
        src/model/Address.cpp include/model/Address.h
        src/model/Vehicle.cpp include/model/Vehicle.h
        src/model/Rent.cpp include/model/Rent.h
        test/master.cpp
        src/model/Bicycle.cpp include/model/Bicycle.h
        include/model/MotorVehicle.h src/model/MotorVehicle.cpp
        include/model/Moped.h src/model/Moped.cpp
        include/model/Car.h src/model/Car.cpp
        include/model/RentsRepository.h src/model/RentsRepository.cpp
        include/model/VehicleRepository.h src/model/VehicleRepository.cpp
        include/model/RentsManager.h src/model/RentsManager.cpp
        include/model/ClientRepository.h src/model/ClientRepository.cpp
        include/model/ClientException.h src/model/ClientException.cpp
        include/model/RentException.h src/model/RentException.cpp
        include/model/clientStandard.h src/model/clientStandard.cpp
        include/model/ClientType.h
        include/model/clientRegular.h src/model/clientRegular.cpp
        include/model/clientPremium.h src/model/clientPremium.cpp
        include/model/ClientManager.h src/model/ClientManager.cpp
        include/model/VehicleManager.h src/model/VehicleManager.cpp include/model/Repository.h include/model/PredicateTemplate.h include/model/AddressException.hpp src/model/AddressException.cpp include/model/VehicleException.hpp src/model/VehicleException.cpp include/model/ClientRepositoryException.hpp src/model/ClientRepositoryException.cpp include/model/RentsRepositoryException.hpp src/model/RentsRepositoryException.cpp include/model/VehicleRepositoryException.hpp src/model/VehicleRepositoryException.cpp src/model/RentsManagerException.cpp include/model/RentsManagerException.h src/model/ClientManagerExceptions.cpp include/model/ClientManagerExceptions.h src/model/VehicleManagerException.cpp include/model/VehicleManagerException.h)


add_library(Biblioteka ${SOURCE_FILES})

#dolacz katalog z plikami naglowkowymi include z projektu biblioteka do sciezek
target_include_directories(Biblioteka PUBLIC include)

#Sekcja testów
find_package(Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(
        SOURCE_TEST_Mat_Lat_FILES
        test/master.cpp
        test/testRent.cpp
        test/TestClient.cpp
        test/testVehicle.cpp
        test/testCar.cpp
        test/testMoped.cpp
        test/testBicycle.cpp
        test/testVehicleRepository.cpp
        test/testClientRepository.cpp
        test/testRentsManager.cpp
        test/testRentsRepository.cpp test/testExceptions.cpp src/model/RentsManagerException.cpp include/model/RentsManagerException.h src/model/ClientManagerExceptions.cpp include/model/ClientManagerExceptions.h src/model/VehicleManagerException.cpp include/model/VehicleManagerException.h)

add_executable (TestBiblioteka ${SOURCE_TEST_Mat_Lat_FILES} )

#dołącz bibliotekę z testowanymi klasami do programu testów
target_link_libraries (TestBiblioteka
        Biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#dodaj test TestClient. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(TestBiblioteki1 TestCRent
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})


enable_testing()