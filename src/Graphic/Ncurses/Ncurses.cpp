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
    endwin();
    initscr();
    nodelay(stdscr, true);
    cbreak();
    noecho();
    curs_set(0);
    getmaxyx(stdscr, _screen_y, _screen_x);
    keypad(stdscr ,TRUE);
    start_color();
    init_pair('O', 1, 1);
    init_pair('#', 2, 2);
    init_pair('A', 4, 4);
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
    char c = drawable[2]->getString().c_str()[0];

    wattron(stdscr, COLOR_PAIR(c));
    mvprintw(position.first, position.second, drawable[2]->getString().c_str());
    wattroff(stdscr, COLOR_PAIR(c));
}

arcade::events_e arcade::Ncurses::pollEvent()
{
    int input = getch();

    for (auto i : KEYS) {
        if (input == (int) i.first) {
            return i.second;
        }
    }
}

void arcade::Ncurses::load(std::vector<std::shared_ptr<IDrawable>> drawable, std::string &name)
{
}

extern "C" arcade::IDisplayModule *createGraphLib()
{
        return (new arcade::Ncurses());
}