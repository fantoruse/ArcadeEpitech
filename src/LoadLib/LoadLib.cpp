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
    void *tmp = dlopen(libName.c_str(), RTLD_NOW);
    if (!tmp)
        throw std::runtime_error(dlerror());
    _openFile.push_back(tmp);
}

void LoadLib::destroyOpenFile() {
    for (auto file: _openFile) {
        dlclose(file);
    }
}