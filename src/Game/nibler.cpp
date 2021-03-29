/*
** EPITECH PROJECT, 2021
** nibler.cpp.c
** File description:
** nibler.cpp.c
*/

#include "nibler.hpp"
#include <cstdlib>
#include <iostream>

Nibler::Nibler() {
    _name = "Nibler";
    _launch = true;
    //_playerPosition = {{}};
    _applePosition = {{}};
    _playerCollision = true;
    _appleCollision = true;
    _wallCollision = true;
    _score = 0;
};

void Nibler::setSnake() {
    int x = 1000;
    int y = 1000;
    std::pair<int, int> tmp(x, y);
    _playerPosition.push_back(std::make_pair((x/2), (y/2)));
    _playerPosition.push_back(std::make_pair((x/2) - 1, (y/2) + 1));
    _playerPosition.push_back(std::make_pair((x/2) - 2, (y/2) + 2));
    _playerPosition.push_back(std::make_pair((x/2) - 3, (y/2) + 3));
    for (int i = 0; i != _playerPosition.size(); i++)
        std::cout << _playerPosition[i].first << "\n";
}

void Nibler::mouvement(int keys) {
    if (keys == 1)
        _playerPosition[0].first += 1;
    if (keys == 2)
        _playerPosition[0].first -= 1;
    if (keys == 3)
        _playerPosition[0].second += 1;
    if (keys == 4)
        _playerPosition[0].second -= 1;
    std::cout << _playerPosition[0].first << "\n";
}

void Nibler::AppleGenerator() {
    int i = 0;

}

Nibler::~Nibler() {};

int main() {
    Nibler a;
    a.setSnake();
    while(1)
        a.mouvement(1);
}