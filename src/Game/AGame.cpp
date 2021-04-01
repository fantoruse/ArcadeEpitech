/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#include "AGame.hpp"

std::vector<arcade::IObject> &AGame::update() const
{
    return _objects;
}