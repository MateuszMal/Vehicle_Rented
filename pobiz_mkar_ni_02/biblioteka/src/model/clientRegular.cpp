//
// Created by student on 26.05.2020.
//

#include "model/clientRegular.h"

float clientRegular::discount() {
    return 0.85f;
}

int clientRegular::maxCars() {
    return 4;
}

std::string clientRegular::getClientType() {
    return "Regular";
}