/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Created by theo,
*/

#include "StaticObject.hpp"

arcade::StaticObject::StaticObject(const std::string &name, const std::vector<std::shared_ptr<IDrawable>> &drawables, std::pair<int,int> pos): _name(name), _drawables(drawables), _position(pos)
{
}

void arcade::StaticObject::setDrawables(std::vector<std::shared_ptr<IDrawable>> drawables)
{
    _drawables = drawables;
}

void arcade::StaticObject::setName(std::string &name)
{
    _name = name;
}

const std::pair<int,int> arcade::StaticObject::getPosition() const
{
    return(_position);
}

const std::vector<std::shared_ptr<arcade::IDrawable>> arcade::StaticObject::getDrawables() const
{
    return(_drawables);
}

const std::string arcade::StaticObject::getName() const
{
    return(_name);
}