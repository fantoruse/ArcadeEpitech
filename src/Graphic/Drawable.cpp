/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Created by theo,
*/

#include "Drawable.hpp"

arcade::Drawable::Drawable(const std::string &obj, std::size_t size,
    arcade::type_e type, arcade::colors_e color
) : _infos(obj), _size(size), _type(type), _color(color)
{
}

std::string arcade::Drawable::getString() const
{
    return _infos;
}
std::size_t arcade::Drawable::getSize() const
{
    return _size;
}
arcade::type_e arcade::Drawable::getType() const
{
    return _type;
}
arcade::colors_e arcade::Drawable::getColor() const
{
    return _color;
}
