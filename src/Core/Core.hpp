/*
** EPITECH PROJECT, 2021
** nibbler.cpp.c
** File description:
** nibbler.cpp.c
*/

#pragma once

#include <string>

namespace arcade {
    class Core {
    public:
        Core() = default;

        ~Core() = default;

        void OpenGame(std::string s);
    };
}