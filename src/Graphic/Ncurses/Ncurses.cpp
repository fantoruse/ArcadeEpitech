/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Created by theo
*/

#include "Ncurses.hpp"
#include <iostream>

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

void arcade::Ncurses::clearWin()
{
    wclear(stdscr);
}

void arcade::Ncurses::refreshWin()
{
    wrefresh(stdscr);
}

void arcade::Ncurses::draw(std::vector<std::shared_ptr<IDrawable>> drawable, std::pair<int, int> position, std::string name)
{
    mvprintw(position.first, position.second, drawable[2]->getString().c_str());
}

arcade::events_e arcade::Ncurses::pollEvent()
{
    int input = getch();

    for (auto &&i : KEYS)
        if (input == i.first)
            return i.second;
        if (input == 't') {
            return arcade::CLOSE;
        }
}

void arcade::Ncurses::load(std::vector<std::shared_ptr<IDrawable>> drawable, std::string &name)
{

}

extern "C" arcade::IDisplayModule *createGraphLib()
{
        return (new arcade::Ncurses());
}