/*
** EPITECH PROJECT, 2021
** LoadLib.cpp.c
** File description:
** LoadLib.cpp.c
*/

#include "LoadLib.hpp"
#include <dlfcn.h>
#include <stdio.h>
#include "Error/Error.hpp"

LoadLib::LoadingLib(char *file) {
    void *OpenFile = dlopen(file, RTLD_NOW);
    void *findFunc = nullptr;

    if (!OpenFile)
        throw Error("Fail to Load Lib");
    findFunc = dlsym(OpenFile, "symbol");
    if (!findFunc)
        throw Error("Fail to find symbol");
}