/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Created by theo
*/

#pragma once

#include "Graphic/ADisplayModule.hpp"
#include <memory>
#include <ncurses.h>
#include <vector>
#include <map>

namespace arcade {
    class Ncurses : public arcade::ADisplayModule {
    public:
        Ncurses();
        ~Ncurses() = default;

        void init();
        void destroy();
        void draw(Drawable drawable, std::pair<int, int> position, int size);
        events_e pollEvent();
        void load();

    private:
        int _screen_x;
        int _screen_y;

        std::string map;
        std::map<std::string, char> _sprites;
    
        static const std::vector<std::pair<int, arcade::events_e>> KEYS = {
        {27, arcade::ESCAPE},
        {KEY_UP, arcade::UP},
        {KEY_DOWN, arcade::DOWN},
        {KEY_LEFT, arcade::LEFT},
        {KEY_RIGHT, arcade::RIGHT},
        {' ', arcade::SPACE},
        };
}
