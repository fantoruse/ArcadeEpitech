/*
** EPITECH PROJECT, 2021
** dynamicFile.cpp.c
** File description:
** dynamicFile.cpp.c
*/

#include "dynamicFile.hpp"
#include "Error/Error.hpp"
#include <iostream>

DynamicFile::DynamicFile()
{
}

DynamicFile::~DynamicFile()
{
}

void DynamicFile::VerifyArg(std::string &argv) const
{
    std::string arguments;

    arguments.assign(argv);
    if (arguments.find("./lib") == std::string::npos)
        throw Error("No such directory: ./lib/");
}