/*
** EPITECH PROJECT, 2021
** LoadLib.hpp.h
** File description:
** LoadLib.hpp.h
*/

#pragma once

#include <string>
#include <iostream>
#include <dlfcn.h>
#include <exception>
#include <functional>
#include <type_traits>
#include "InterfaceGame/Iinterface.hpp"

class LoadLib
{
public:

    LoadLib() = default;
    ~LoadLib() { /*dlclose(_openFile);*/ };
    void initHandler(const std::string &libName) {
        _openFile = dlopen(libName.c_str(), RTLD_LAZY);
        if (!_openFile) 
            throw std::runtime_error(dlerror());
    }

    template <typename T> //, typename = std::enable_if<std::is_base_of<Iinterface, T>::value
    std::function<T> loadingLib(const std::string &functionName) const
    {
        T *p = (T*)(dlsym(_openFile, functionName.c_str()));
        if (!p)
            throw std::runtime_error(dlerror());
        //dlclose(_openFile);
        return std::function<T>(p);
    }
private:
        void *_openFile = nullptr;

};
