/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#ifndef ARCADE_AGAME_HPP
#define ARCADE_AGAME_HPP

#include "IGame.hpp"

class AGame: public IGame
{
public:
    AGame() = default;
    std::vector<arcade::IObject> &update() const override;
protected:
    std::pair<float, float> _playerPosition;
    std::vector<arcade::IObject> &_objects;
};

#endif //ARCADE_AGAME_HPP
