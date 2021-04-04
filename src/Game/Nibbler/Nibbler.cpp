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

arcade::Nibbler::Nibbler(): arcade::AGame("nibbler") , _applePosition(0, 0), _score(0), _name("Nibbler"), _isApple(false), _objects()
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

std::shared_ptr<arcade::IObject> arcade::Nibbler::init_object(bool is_static, std::string name, std::vector<std::shared_ptr<IDrawable>> drawables, std::pair<int,int> pos)
{
    if (is_static)
        return(std::make_shared<arcade::IObject>(new StaticObject(name, drawables, pos)));
    else
        return(std::make_shared<arcade::IObject>(new MovableObject(name, drawables, pos)));
}

void arcade::Nibbler::init_all_object()
{

}

const std::vector<std::shared_ptr<arcade::IObject>> arcade::Nibbler::play()
{
    if (_objects.empty())
        init_all_object();
    return;
}

const std::string arcade::Nibbler::getName() const {
    std::cout << "bite" << "\n";
    return "test";
}

void arcade::Nibbler::AppleGenerator()
{
    float rx = 0;
    float ry = 0;
    bool end = false;

    if (_isApple)
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
    _isApple = true;
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

static const std::map<arcade::events_e, std::pair<float, float>> DIRECTIONS = {
    {arcade::UP, std::make_pair(-1, 0)},
    {arcade::DOWN, std::make_pair(1, 0)},
    {arcade::LEFT, std::make_pair(0, -1)},
    {arcade::RIGHT, std::make_pair(0, 1)}
};

void arcade::Nibbler::move(arcade::events_e dir)
{
    auto finded = DIRECTIONS.find(dir);

    if (finded == DIRECTIONS.end() || collisionWall(dir))
        return;
    _playerPosition.first += DIRECTIONS.at(dir).first;
    _playerPosition.second += DIRECTIONS.at(dir).second;
}

bool arcade::Nibbler::collisionWall(arcade::events_e dir)
{
    float y = _playerPosition.first + DIRECTIONS.at(dir).first;
    float x = _playerPosition.second + DIRECTIONS.at(dir).second;

    if ((y <= 1 || x <= 1) || _map[y][x] == '#')
        return true;
    return false;
}

extern  "C" arcade::IGame *GetGame() {
        auto b = new arcade::Nibbler();
        return b;
}