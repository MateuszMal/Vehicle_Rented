//
// Created by student on 27.05.2020.
//

#include "model/clientPremium.h"

float clientPremium::discount() {
    return 0.75f;
}

int clientPremium::maxCars() {
    return 8;
}

std::string clientPremium::getClientType() {
    return "Premium";
}
