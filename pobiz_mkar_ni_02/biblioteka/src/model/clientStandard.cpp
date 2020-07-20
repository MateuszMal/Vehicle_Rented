//
// Created by student on 26.05.2020.
//

#include <model/clientStandard.h>

float clientStandard::discount() {
    return 1;
}

int clientStandard::maxCars() {
    return 2;
}

std::string clientStandard::getClientType() {
    return "Standard";
}