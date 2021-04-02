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
class Nibbler : public AGame {
public:
    Nibbler();
    ~Nibbler() override;

    void AppleGenerator();
    void updateSnake();
    void mouvement(int i);
    void play() override;
    std::vector<arcade::IObject> update() const override;

    private:
        std::pair<float, float> _applePosition;
        bool _is_apple;
        unsigned long int _score;
        std::string _name;
        std::vector<std::string> _map;
        std::vector<std::pair<float, float>> _enemies;
    
    private:
        void loadMap();
    };
}