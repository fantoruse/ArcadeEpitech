/*
** EPITECH PROJECT, 2021
** LoadLib.cpp.c
** File description:
** LoadLib.cpp.c
*/

#include "LoadLib.hpp"
#include <dlfcn.h>
#include "Error/Error.hpp"

extern "C" {
int entryPoint() {
    void strcat();
}
}

void LoadLib::LoadingLib(std::string files) {
    void *OpenFile = dlopen(files.c_str(), RTLD_NOW);
    void *findFunc = nullptr;

    if (!OpenFile)
        throw Error(dlerror());
    findFunc = dlsym(OpenFile, "strcat");
    if (!findFunc)
        throw Error(dlerror());
    return findFunc;
}