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
        bool collisionWall(arcade::events_e dir);
        std::shared_ptr<arcade::IObject> init_object(bool is_static, const std::string &name, const std::vector<std::shared_ptr<arcade::IDrawable>> &drawables, std::pair<float,float> pos);
        void init_all_object();
        std::vector<std::shared_ptr<arcade::IDrawable>> createDrawableVector(const std::string &name) const;

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

static const std::map<std::string, std::vector<arcade::Drawable>> DRAWABLE_LIST = {
    {"Wall", {{"wall.png", 100, arcade::SPRITE, arcade::NONE},
        {"Rect", 100, arcade::SHAPE, arcade::WHITE},
        {"#", 1, arcade::TEXT, arcade::WHITE}}}
};