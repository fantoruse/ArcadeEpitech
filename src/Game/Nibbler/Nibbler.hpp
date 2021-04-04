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
#include "IGame.hpp"
#include "Object/IObject.hpp"
#include "Object/StaticObject.hpp"
#include "Object/MovableObject.hpp"

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
        std::shared_ptr<arcade::IObject> init_object(bool is_static, std::string name, std::vector<std::shared_ptr<IDrawable>> drawables, std::pair<int,int> pos);
        void init_all_object();

    private:
        std::pair<float, float> _applePosition;
        unsigned long int _score;
        std::string _name;
        std::vector<std::string> _map;
        std::vector<std::pair<float, float>> _enemies;
        std::vector<std::shared_ptr<arcade::IObject>> _objects;
        bool _isApple;
    };
}