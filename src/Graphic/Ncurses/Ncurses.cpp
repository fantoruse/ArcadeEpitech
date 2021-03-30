/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Created by theo
*/

#include "Ncurses.hpp"

arcade::Ncurses::Ncurses(): ADisplayModule("NCURSES")
{
}

void arcade::Ncurses::init()
{
    initscr();
    nodelay(stdscr, true);
    cbreak();
    noecho();
    curs_set(0);
    getmaxyx(stdscr, _screen_y, _screen_x);
    start_color();
}

void arcade::Ncurses::destroy()
{
    endwin();
}

void arcade::Ncurses::draw (Drawable drawable, std::pair<int, int> position, int size)
{
    mvprintw(position.first, position.second, drawable.getType(CHARACTER[c]));
}

arcade::events_e arcade::Ncurses::pollEvent()
{
    int input = getch();

    for (auto &&i : KEYS)
        if (input == i.first)
            return i.second;
}

void arcade::Ncurses::load()
{

}