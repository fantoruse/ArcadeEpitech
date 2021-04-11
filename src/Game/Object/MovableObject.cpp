/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Created by theo,
*/

#include "MovableObject.hpp"

arcade::MovableObject::MovableObject(const std::string &name,
    std::vector<std::shared_ptr<arcade::IDrawable>> drawables,
    std::pair<int, int> pos
) : StaticObject(name, drawables, pos)
{
}

void arcade::MovableObject::setPosition(std::pair<int, int> pos)
{
    _position = pos;
}