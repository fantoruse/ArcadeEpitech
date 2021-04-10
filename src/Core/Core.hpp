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
        ~Core() = default;

        void OpenGame(const LoadLib &ldb,const std::string &s);
        void OpenFirstLibs(std::string &s, LoadLib &ldb);
        void OpenLibsInLibs(const LoadLib &ldb, const std::string &name);
        void gameLoop(LoadLib &ldb);
        void getTypes(const std::string &s, LoadLib &b);
        void game(std::shared_ptr<IGame> &gaming, events_e event, std::shared_ptr<IDisplayModule> &libs);
        void clearLibs() {
            _loadGames.clear();
            _loadLibs.clear();
        }

    protected:
        std::vector<std::pair<std::string, std::shared_ptr<IGame>>> _loadGames;
        std::vector<std::pair<std::string, std::shared_ptr<IDisplayModule>>> _loadLibs;
    };
}