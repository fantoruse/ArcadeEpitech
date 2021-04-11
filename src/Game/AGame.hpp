/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#pragma once

#include "IGame.hpp"
#include "Object/IObject.hpp"

namespace arcade {
    class AGame: public IGame {
    public:
        AGame(std::string const &name);
        virtual ~AGame();

    protected:
        std::pair<float, float> _playerPosition;
        std::vector<std::shared_ptr<IObject>> _objects;
        std::string _name;
    };
}
