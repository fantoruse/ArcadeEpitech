/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Created by theo
*/

#ifndef NCURSES_HPP
#define NCURSES_HPP

#include "Graphic/ADisplayModule.hpp"
#include <memory>
#include <ncurses.h>

namespace arcade {
    class Ncurses : public arcade::ADisplayModule {
    public:
        Ncurses();
        ~Ncurses() = default;

        void draw(Drawable drawable, std::pair<int, int> position, int size);
        void init();
        void destroy();
        events_e pollEvent();
        void load();
        std::unique_ptr<IDisplayModule> createGraphLib();

    protected:
    private:
        int _screen_x;
        int _screen_y;
    };
}

#endif