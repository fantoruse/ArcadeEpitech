/*
** EPITECH PROJECT, 2021
** LoadLib.cpp.c
** File description:
** LoadLib.cpp.c
*/

#include "LoadLib.hpp"
#include <dlfcn.h>
#include "Error/Error.hpp"
#include <iostream>

void LoadLib::initHandler(const std::string &libName) {
    _openFile = dlopen(libName.c_str(), RTLD_LAZY);
    std::cout << "OPEN == "<<_openFile << std::endl;
    if (!_openFile)
        throw std::runtime_error(dlerror());
}

