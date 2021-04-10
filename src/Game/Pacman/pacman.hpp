/*
** EPITECH PROJECT, 2021
** pacman.hpp
** File description:
** pacman.hpp
*/

#pragma once

#include <map>
#include <vector>
#include <string>
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <utility>
#include <iostream>
#include <functional>

#include "AGame.hpp"
#include "IGame.hpp"
#include "Object/IObject.hpp"
#include "Graphic/Drawable.hpp"
#include "Object/StaticObject.hpp"
#include "Object/MovableObject.hpp"

namespace arcade {
class Pacman : public AGame {
    public:
        Pacman();
        ~Pacman() override;

        void move(arcade::events_e dir);
        const std::vector<std::shared_ptr<IObject>> play(arcade::events_e) override;
        const std::string &getName() const override;
        bool isLost() override;

    private:
        void loadMap();
        void headMov();
        bool collisionWall(arcade::events_e dir);
        std::shared_ptr<arcade::IObject> init_object(bool is_static, const std::string &name, const std::vector<std::shared_ptr<arcade::IDrawable>> &drawables, std::pair<float,float> pos);
        void init_all_object();
        std::vector<std::shared_ptr<arcade::IDrawable>> createDrawableVector(const std::string &name) const;
        std::shared_ptr<arcade::IObject> updateScore();
        void eatPacgum();
        void enemiesMoves();
        void enemiesGetOut();
        void checkTp();
        void checkStats();

    private:
        std::pair<float, float> _playerMov;
        unsigned long int _score;
        std::string _name;
        std::vector<std::string> _map;
        std::vector<std::pair<float, float>> _enemies;
        std::vector<std::pair<float, float>> _enemiesMov;
        std::vector<std::shared_ptr<arcade::IObject>> _objects;
        bool _started;
        std::vector<std::shared_ptr<arcade::IObject>> _comsomable;
        std::vector<std::shared_ptr<arcade::IObject>> _special;
        bool _stats;
        int _slow;
    };
}

static const std::map<std::string, std::vector<arcade::Drawable>> DRAWABLE_LIST = {
    {"Wall", {{"./resources/wall.jpeg", 50, arcade::SPRITE, arcade::NONE},
        {"Rect", 50, arcade::SHAPE, arcade::YELLOW},
        {"#", 1, arcade::TEXT, arcade::YELLOW}}},
    {"player", {{"./resources/player.png", 50, arcade::SPRITE, arcade::NONE},
        {"Rect", 50, arcade::SHAPE, arcade::GREEN},
        {"X", 1, arcade::TEXT, arcade::GREEN}}},
    {"enemie", {{"./resources/enemi.png", 50, arcade::SPRITE, arcade::NONE},
        {"Rect", 50, arcade::SHAPE, arcade::BLUE},
        {"O", 1, arcade::TEXT, arcade::BLUE}}},
    {"stat", {{"./resources/enemi.png", 50, arcade::SPRITE, arcade::CYAN},
        {"Rect", 50, arcade::SHAPE, arcade::CYAN},
        {"O", 1, arcade::TEXT, arcade::CYAN}}},
    {"apple", {{"./resources/apple.png", 50, arcade::SPRITE, arcade::NONE},
        {"Rect", 50, arcade::SHAPE, arcade::RED},
        {"A", 1, arcade::TEXT, arcade::RED}}},
    {"ball", {{"./resources/ball.png", 50, arcade::SPRITE, arcade::NONE},
        {"Rect", 50, arcade::SHAPE, arcade::WHITE},
        {".", 1, arcade::TEXT, arcade::WHITE}}},
    {"special", {{"./resources/special.png", 50, arcade::SPRITE, arcade::NONE},
        {"Rect", 50, arcade::SHAPE, arcade::MAGENTA},
        {"0", 1, arcade::TEXT, arcade::MAGENTA}}},
    };