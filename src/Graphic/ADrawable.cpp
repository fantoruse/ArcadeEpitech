/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Created by theo,
*/

#include "ADrawable.hpp"

void arcade::ADisplayModule::setSize(int size)
{
    _size = size;
}

std::size_t arcade::ADisplayModule::getSize()
{
    return (_size);
}