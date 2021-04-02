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
#include "../AGame.hpp"

namespace arcade {
    class Nibbler : public AGame {
        public:
            Nibbler();
            ~Nibbler() = default;

            void AppleGenerator();
            void updateSnake();
            void mouvement(int i);

        private:
            std::pair<float, float> _applePosition;
            unsigned long int _score;
            std::string _name;
            std::vector<std::string> _map;
            std::vector<std::pair<float, float>> _enemies;
    };
}