//
// Created by student on 16.06.2020.
//

#include "model/ClientRepositoryException.hpp"

using namespace std;

ClientReposiroryException::ClientReposiroryException(const string &arg) : logic_error(arg){}

const string ClientReposiroryException::exceptionNoClient = "CLIENT IS NOT IN REPOSITORY";
const string ClientReposiroryException::exceptionClientPtrNullPtr = "CLIENT_PTR IS NULL";
const string ClientReposiroryException::exceptionClientExist = "CLIENT EXISTS IN REPOSITORY";