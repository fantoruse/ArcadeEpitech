/*
** EPITECH PROJECT, 2021
** nibbler.cpp.c
** File description:
** nibbler.cpp.c
*/

#include "Nibbler.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>

arcade::Nibbler::Nibbler(): arcade::AGame() , _applePosition(0, 0), _score(0), _name("Nibbler"), _is_apple(false)
{
    int n = 0;

    std::srand(std::time(0));
    loadMap();
    while (n != 4) {
        _enemies.push_back(std::make_pair((_playerPosition.first - n), _playerPosition.second));
        n++;
    }
}

arcade::Nibbler::~Nibbler(){}

void arcade::Nibbler::updateSnake()
{
    auto it = _enemies.begin();
    auto temp1 = _enemies[0];
    auto temp2 = _enemies[0];

    _enemies[0] = std::make_pair(_playerPosition.first, _playerPosition.second);
    it++;
    for (int o=1; it != _enemies.end(); ++o, it++) {
        temp2 = std::make_pair(_enemies[o].first, _enemies[o].second);
        _enemies[o] = std::make_pair(temp1.first, temp1.second);
        temp1 = temp2;
    }
}

void arcade::Nibbler::play(){}

std::vector<arcade::IObject> arcade::Nibbler::update() const {}

void arcade::Nibbler::AppleGenerator()
{
    float rx = 0;
    float ry = 0;
    bool end = false;

    if (_is_apple)
        return;
    while (!end) {
        ry = rand() % 18;
        rx = rand() % 18;
        for (auto it: _enemies) {
            if ((it.first != rx and it.second != ry) || _map[rx][ry] != '#') {
                end = true;
                break;
            }
        }
    _applePosition.first = rx;
    _applePosition.second = ry;
    _is_apple = true;
    }
}

void arcade::Nibbler::loadMap()
{
    std::ifstream file(".conf/Nibbler_map.txt");
    std::string line;

    if (!file)
        return;
    while (std::getline(file, line)) {
        _map.push_back(line);
    }
}

int main() {
    int i = 0;
    arcade::Nibbler a;
    while(i!=5) {
        a.updateSnake();
        a.AppleGenerator();
        i++;
        }
    return 0;
}
