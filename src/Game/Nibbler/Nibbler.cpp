/*
** EPITECH PROJECT, 2021
** nibbler.cpp.c
** File description:
** nibbler.cpp.c
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <map>
#include "Nibbler.hpp"

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

static const std::map<arcade::events_e, std::pair<float, float>> DIRECTIONS = {
    {arcade::UP, std::make_pair(-1, 0)},
    {arcade::DOWN, std::make_pair(1, 0)},
    {arcade::LEFT, std::make_pair(0, -1)},
    {arcade::RIGHT, std::make_pair(0, 1)}
};

void arcade::Nibbler::move(arcade::events_e dir)
{
    auto finded = DIRECTIONS.find(dir);

    if (finded == DIRECTIONS.end() || colisionWall(dir))
        return;
    _playerPosition.first += DIRECTIONS.at(dir).first;
    _playerPosition.second += DIRECTIONS.at(dir).second;
}

bool arcade::Nibbler::colisionWall(arcade::events_e dir)
{
    float y = _playerPosition.first + DIRECTIONS.at(dir).first;
    float x = _playerPosition.second + DIRECTIONS.at(dir).second;

    if ((y <= 1 || x <= 1) || _map[y][x] == '#')
        return true;
    return false;
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
