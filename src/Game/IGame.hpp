/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#ifndef ARCADE_IGAME_HPP
#define ARCADE_IGAME_HPP

#include <vector>
#include "IObject.hpp"

class IGame
{
public:
    virtual void play() = 0;
    virtual std::vector<arcade::IObject> update() const = 0;
};

#endif //ARCADE_IGAME_HPP
