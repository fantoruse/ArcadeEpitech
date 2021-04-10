/*
** EPITECH PROJECT, 2021
** nibbler.cpp.c
** File description:
** nibbler.cpp.c
*/

#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <map>
#include "Graphic/IDisplayModule.hpp"
#include "Game/IGame.hpp"
#include "LoadLib/LoadLib.hpp"

namespace arcade {
    class Core {
    public:
        Core() = default;
        ~Core();

        void OpenGame(const LoadLib &ldb,const std::string &s);
        void OpenFirstLibs(std::string &s, LoadLib &ldb);
        void OpenLibsInLibs(const LoadLib &ldb, const std::string &name);
        void gameLoop(LoadLib &ldb);
        void getTypes(const std::string &s, LoadLib &b);
        void game(IGame *gaming, events_e event, IDisplayModule *libs);

    protected:
        std::vector<std::pair<std::string, IGame *>> _loadGames;
        std::vector<std::pair<std::string, IDisplayModule *>> _loadLibs;
    };
}