/*
** EPITECH PROJECT, 2021
** nibbler.hpp.h
** File description:
** nibbler.hpp.h
*/

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <chrono>
#include "AGame.hpp"

namespace arcade {
    enum events_e {
    CLOSE,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SPACE,
    ESCAPE,
    NOTHING
};
class Nibbler : public AGame {
public:
    Nibbler();
    ~Nibbler() override;

    void AppleGenerator();
    void updateSnake();
    void move(arcade::events_e dir);
    const std::vector<std::shared_ptr<IObject>> play() override;
    const std::string getName() const override;
private:
    void loadMap();
    bool collisionWall(arcade::events_e dir);

private:
    std::pair<float, float> _applePosition;
    unsigned long int _score;
    std::string _name;
    std::vector<std::string> _map;
    std::vector<std::pair<float, float>> _enemies;
    bool _isApple;
};
}