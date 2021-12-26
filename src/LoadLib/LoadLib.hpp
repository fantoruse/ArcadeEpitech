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
#include <iterator>
#include <vector>

class LoadLib {
public:

    LoadLib() = default;
    ~LoadLib() = default;
    void initHandler(const std::string &libName);
    void destroyOpenFile();
    template<typename T>
    std::function<T> loadingLib(const std::string &functionName) const
    {

        T *p = (T *)(dlsym(_openFile[(_openFile.size() - 1)],
            functionName.c_str()));
        if (!p)
            throw std::runtime_error(dlerror());
        return std::function<T>(p);
    }

private:
    std::vector<void *> _openFile;
};
