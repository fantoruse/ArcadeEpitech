/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#include "AGame.hpp"

arcade::AGame::AGame(std::string const &name) : IGame(), _playerPosition(17,17), _objects(), _name(name) {}

arcade::AGame::~AGame() {}