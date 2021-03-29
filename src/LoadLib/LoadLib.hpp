/*
** EPITECH PROJECT, 2021
** LoadLib.hpp.h
** File description:
** LoadLib.hpp.h
*/

#pragma once

#include <string>
#include <iostream>
#include "InterfaceGame/Iinterface.hpp"
#include <dlfcn.h>
#include <exception>
#include <type_traits>

class LoadLib
{
public:
    void *openFile = nullptr;

    LoadLib() = default;
    ~LoadLib() { dlclose(openFile); };
    void initHandler(const std::string libName) {
        openFile = dlopen(libName.c_str(), RTLD_LAZY);
        if (!openFile)
            throw std::runtime_error(dlerror());
    }

    template <typename T> //, typename = std::enable_if<std::is_base_of<Iinterface, T>::value>>
    T loadingLib(const std::string functionName)
    {
        T (*findFunc)() = nullptr;
        findFunc = (T(*)(void))(dlsym(openFile, functionName.c_str()));
        if (!findFunc)
            throw std::runtime_error(dlerror());
        return findFunc();
    }
};
