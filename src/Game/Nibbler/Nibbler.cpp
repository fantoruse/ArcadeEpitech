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

arcade::Nibbler::Nibbler(): arcade::AGame() , _applePosition(0, 0), _score(0), _name("Nibbler")
{
    int n = 0;

    _map = {
        {}
    };
    while (n != 4) {
        _enemies.push_back(std::make_pair((_playerPosition.first - n), _playerPosition.second));
        n++;
    }
}

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
    for(auto i: _enemies)
        std::cout << "FIRST HEHE    = = =" << i.first << " | " << "SECOND HERE = = = " << i.second ;
    std::cout << std::endl;
}

arcade::Nibbler::~Nibbler(){}

void arcade::Nibbler::play(){}

std::vector<arcade::IObject> arcade::Nibbler::update() const {}

void arcade::Nibbler::loadMap()
{
    std::ifstream file(".conf/Nibbler_map.txt");
    std::string line;

    if (!file)
        return;
    while (std::getline(file, line))
        _map.push_back(line);
}

int main() {
    int i = 0;
    arcade::Nibbler a;
    while(i!=5) {
        a.updateSnake();
        i++;
        }
    return 0;
}
