/*
** EPITECH PROJECT, 2021
** nibbler.cpp.c
** File description:
** nibbler.cpp.c
*/

#include "Nibbler.hpp"
#include <cstdlib>
#include <iostream>

arcade::Nibbler::Nibbler(): arcade::AGame() : _applePosition(0, 0), _score(0), _name("Nibbler")
{
    int n = 0;

    _map = {
        {}
    };
    while (n != 4) {
        _enemies.push_back(std::make_paire(_playerPosition.first() - n, _playerPosition.second));
        n++;
    }
}

void arcade::Nibbler::updateSnake()
{
    auto it = _enemies.begin();
    auto temp1 = _enemies[0];
    auto temp2 = _enemies[0];

    it = std::make_paire(_playerPosition.first(), _playerPosition.second());
    it++;
    while (it != _enemies.end()) {
        temp2 = std::make_paire(it.first(), it.second());
        it = std::make_paire(temp1.first(), temp1.second());
        temp1 = temp2;
        it++;
    }
}

int main() {
    arcade::Nibbler a;
    while(1)
        a.updateSnake();
        a.mouvement(1);
}
