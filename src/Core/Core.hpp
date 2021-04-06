/*
** EPITECH PROJECT, 2021
** nibbler.cpp.c
** File description:
** nibbler.cpp.c
*/

#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "Graphic/IDisplayModule.hpp"
#include "Game/IGame.hpp"

namespace arcade {
    class Core {
    public:
        Core();
        ~Core() = default;

        void OpenGame();
        void OpenFirstLibs(std::string);
        void OpenLibsInLibs(std::string);
        void switchLibs(events_e);
        void gameLoop();

    protected:
        std::vector<std::pair<std::string, IGame*>> _loadGames;
        std::vector<std::pair<std::string, IDisplayModule*>> _loadLibs;
        std::string _actualLibs;
        std::string _actualGames;
    };
}