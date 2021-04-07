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

arcade::Nibbler::Nibbler(): arcade::AGame("nibbler") , _applePosition(0, 0), _score(0), _name("Nibbler"), _map(), _enemies(), _objects(), _isApple(false)
{
    int n = 0;

    std::srand(std::time(0));
    loadMap();
    while (n != 4) {
        _enemies.push_back(std::make_pair((_playerPosition.first), _playerPosition.second - n));
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
const std::vector<std::shared_ptr<arcade::IObject>> arcade::Nibbler::play([[maybe_unused]]arcade::events_e events)
{
    if (_objects.empty())
        init_all_object();
    //move(events);
    headMov();
    //updateSnake();
    AppleGenerator();
    auto temp = _objects;
    temp.push_back(init_object(true, "apple",
            createDrawableVector("apple"), std::make_pair(_applePosition.first, _applePosition.second)));
    for (auto i = _enemies.begin(); i != _enemies.end(); i += 1)
        temp.push_back(init_object(true, "enemie",
                    createDrawableVector("enemie"), std::make_pair(i->first, i->second)));
    return temp;
}

const std::string arcade::Nibbler::getName() const {
    return _name;
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
            if ((it.first != ry and it.second != rx) && _map[ry][rx] != '#') {
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
    _playerMov = DIRECTIONS.at(dir);
}

void arcade::Nibbler::headMov()
{
    _enemies[0].first += _playerMov.first;
    _enemies[0].second += _playerMov.second;
}

bool arcade::Nibbler::collisionWall(arcade::events_e dir)
{
    float y = _enemies[0].first + DIRECTIONS.at(dir).first;
    float x = _enemies[0].second + DIRECTIONS.at(dir).second;

    if ((y <= 1 || x <= 1) || _map[y][x] == '#')
        return true;
    return false;
}
std::shared_ptr<arcade::IObject> arcade::Nibbler::init_object(bool is_static,
    const std::string &name, const std::vector<std::shared_ptr<arcade::IDrawable>> &drawables,
    std::pair<float, float> pos)
{
    if (is_static)
        return std::make_shared<arcade::StaticObject>(StaticObject(name, drawables, pos));
    else
        return std::make_shared<arcade::MovableObject>(MovableObject(name, drawables, pos));
}


void arcade::Nibbler::init_all_object()
{
    for (std::size_t y = 0; y < _map.size(); y++) {
        for (std::size_t x = 0; _map[y][x] != '\0'; x++) {
            if (_map[y][x] == '#') {
                _objects.push_back(init_object(true, "Wall",
                    createDrawableVector("Wall"), std::make_pair(y, x)));
            }
        }
    }
}

std::vector<std::shared_ptr<arcade::IDrawable>> arcade::Nibbler::createDrawableVector(
    const std::string &name) const
{
    std::vector<std::shared_ptr<arcade::IDrawable>> dest;

    if (DRAWABLE_LIST.find(name) == DRAWABLE_LIST.end())
        return dest;
    dest.push_back(std::make_shared<arcade::Drawable>(DRAWABLE_LIST.at(name)[0]));
    dest.push_back(std::make_shared<arcade::Drawable>(DRAWABLE_LIST.at(name)[1]));
    dest.push_back(std::make_shared<arcade::Drawable>(DRAWABLE_LIST.at(name)[2]));
    return dest;
}

extern  "C" arcade::IGame *GetGame() {
        auto b = new arcade::Nibbler();
        return b;
}