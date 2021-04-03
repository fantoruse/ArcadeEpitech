/*
** EPITECH PROJECT, 2021
** Iinterface.hpp.h
** File description:
** Iinterface.hpp.h
*/

#pragma once

#include <string>

class Iinterface {
public:
    virtual ~Iinterface() = default;
    virtual void draw() = 0;
};
