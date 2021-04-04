/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#include "Core/Core.hpp"
#include "LoadLib/LoadLib.hpp"
#include "Game/IObject.hpp"
#include "Game/IGame.hpp"

namespace arcade {

void Core::OpenGame(std::string path) {
    LoadLib ldb;

    ldb.initHandler(path);
    auto libs = ldb.loadingLib<IGame *(void)>("GetGame")();
    libs->getName();
//    libs->getName();
}
}