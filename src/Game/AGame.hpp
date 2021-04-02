/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#pragma once

#include "IGame.hpp"
#include "IObject.hpp"

namespace arcade {
    class AGame: public IGame {
    public:
        AGame();
        virtual ~AGame();

    protected:
        std::pair<float, float> _playerPosition;
        std::vector<arcade::IObject> _objects;
    };
}
