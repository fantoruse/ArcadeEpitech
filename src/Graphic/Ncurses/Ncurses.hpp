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

namespace arcade {
    class Ncurses : public arcade::ADisplayModule {
    public:
        Ncurses();
        ~Ncurses() override;

        void init() override;
        void destroy() override;
        void clearWin() override;
        void refreshWin() override;
        void draw(std::vector<std::shared_ptr<IDrawable>> drawable,std::pair<int, int> position, const std::string &name) override;
        events_e pollEvent() override;
        void load(std::vector<std::shared_ptr<IDrawable>> drawable, const std::string &name) override;
        std::string getForm(std::string str) override;
        void drawText(const std::string &string, std::pair<int, int> position) override;

    private:
        int _screen_x;
        int _screen_y;

        std::string map;
        std::map<std::string, char> _sprites;
    };
}

static const std::vector<std::pair<int, arcade::events_e>> KEYS = {
    {KEY_UP, arcade::UP},
    {KEY_DOWN, arcade::DOWN},
    {KEY_LEFT, arcade::LEFT},
    {KEY_RIGHT, arcade::RIGHT},
    {' ', arcade::SPACE},
    {'n', arcade::NEXT},
    {'p', arcade::PREV},
    {'q', arcade::CLOSE},
    {'r', arcade::RESTART},
    {'g', arcade::PREV_GAME},
    {'h', arcade::NEXT_GAME},
    {27, arcade::ESCAPE},
};
