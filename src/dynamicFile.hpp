/*
** EPITECH PROJECT, 2021
** dynamicFile.hpp.h
** File description:
** dynamicFile.hpp.h
*/

#pragma once

#include <string>

class DynamicFile {
public:
    DynamicFile();
    ~DynamicFile();
    void VerifyArg(char *argv) const;
};
