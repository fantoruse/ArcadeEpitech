/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Created by theo
*/

#pragma once

#include <memory>
#include <ncurses.h>
#include <vector>
#include <map>
#include "ADisplayModule.hpp"

static const std::vector<std::pair<int, arcade::events_e>> KEYS = {
{27, arcade::ESCAPE},
{KEY_UP, arcade::UP},
{KEY_DOWN, arcade::DOWN},
{KEY_LEFT, arcade::LEFT},
{KEY_RIGHT, arcade::RIGHT},
{' ', arcade::SPACE},
{'s', arcade::NEXT},
{'q', arcade::PREV},
};

namespace arcade {
    class Ncurses : public arcade::ADisplayModule {
    public:
        Ncurses();
        ~Ncurses() = default;

        void init() override;
        void destroy() override;
        void clearWin() override;
        void refreshWin() override;
        void draw(std::vector<std::shared_ptr<IDrawable>> drawable, std::pair<int, int> position, std::string &name) override;
        events_e pollEvent() override;
        void load(std::vector<std::shared_ptr<IDrawable>> drawable, std::string &name) override;
    private:
        int _screen_x;
        int _screen_y;

        std::string map;
        std::map<std::string, char> _sprites;
    };
}
