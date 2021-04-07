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
#include <functional>

#include "AGame.hpp"
#include "IGame.hpp"
#include "Object/IObject.hpp"
#include "Object/StaticObject.hpp"
#include "Object/MovableObject.hpp"
#include "Graphic/Drawable.hpp"

namespace arcade {
class Nibbler : public AGame {
    public:
        Nibbler();
        ~Nibbler() override;

        void AppleGenerator();
        void updateSnake();
        void move(arcade::events_e dir);
        const std::vector<std::shared_ptr<IObject>> play(arcade::events_e) override;
        const std::string getName() const override;
        bool isLost() const {return false;};

    private:
        void loadMap();
        void headMov();
        bool collisionWall(arcade::events_e dir);
        std::shared_ptr<arcade::IObject> init_object(bool is_static, const std::string &name, const std::vector<std::shared_ptr<arcade::IDrawable>> &drawables, std::pair<float,float> pos);
        void init_all_object();
        std::vector<std::shared_ptr<arcade::IDrawable>> createDrawableVector(const std::string &name) const;
        void eatApple();
        std::shared_ptr<arcade::IObject> updateScore();

    private:
        std::pair<float, float> _applePosition;
        std::pair<int, int> _playerMov;
        unsigned long int _score;
        std::string _name;
        std::vector<std::string> _map;
        std::vector<std::pair<float, float>> _enemies;
        std::vector<std::shared_ptr<arcade::IObject>> _objects;
        bool _isApple;
        bool _started;
    };
}

static const std::map<std::string, std::vector<arcade::Drawable>> DRAWABLE_LIST = {
    {"Wall", {{"wall.png", 10, arcade::NO_TYPE, arcade::NONE},
        {"Rect", 50, arcade::SHAPE, arcade::WHITE},
        {"#", 1, arcade::TEXT, arcade::WHITE}}},
    {"enemie", {{"enemie.png", 10, arcade::NO_TYPE, arcade::NONE},
        {"Rect", 50, arcade::SHAPE, arcade::BLUE},
        {"O", 10, arcade::TEXT, arcade::WHITE}}},
    {"apple", {{"apple.png", 10, arcade::NO_TYPE, arcade::NONE},
        {"Rect", 50, arcade::SHAPE, arcade::RED},
        {"A", 1, arcade::TEXT, arcade::WHITE}}},
    };