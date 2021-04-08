/*
** EPITECH PROJECT, 2021
** dynamicFile.cpp.c
** File description:
** dynamicFile.cpp.c
*/

#include "dynamicFile.hpp"
#include "Error/Error.hpp"
#include <iostream>

DynamicFile::DynamicFile() {}

DynamicFile::~DynamicFile() {}

void DynamicFile::VerifyArg(char *argv) const {
    std::string arguments;

    arguments.assign(argv);
    if (arguments.find("./lib") == std::string::npos)
        throw Error("Il n'y a pas de dossier : ./lib/");
}