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
    init_pair(arcade::WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(arcade::BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(arcade::GREEN, COLOR_GREEN, COLOR_GREEN);
    init_pair(arcade::RED, COLOR_RED, COLOR_RED);
    init_pair(arcade::BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(arcade::CYAN, COLOR_CYAN, 0);
    init_pair(arcade::MAGENTA, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(arcade::YELLOW, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(arcade::NONE, 0, 0);
}

void arcade::Ncurses::destroy()
{
    endwin();
    wclear(stdscr);
}

void arcade::Ncurses::clearWin()
{
    wclear(stdscr);
}

void arcade::Ncurses::refreshWin()
{
    wrefresh(stdscr);
}

void arcade::Ncurses::draw(std::vector<std::shared_ptr<IDrawable>> drawable, std::pair<int, int> position, [[maybe_unused]] std::string name)
{
    arcade::colors_e color = drawable[2]->getColor();

    wattron(stdscr, COLOR_PAIR(color));
    mvprintw(position.first, position.second, drawable[2]->getString().c_str());
    wattroff(stdscr, COLOR_PAIR(color));
}

arcade::events_e arcade::Ncurses::pollEvent()
{
    int input = getch();

    for (auto i : KEYS) {
        if (input == (int) i.first) {
            return i.second;
        }
    }
    return arcade::NOTHING;
}

void arcade::Ncurses::load([[maybe_unused]] std::vector<std::shared_ptr<IDrawable>> drawable, [[maybe_unused]] std::string &name)
{
}
arcade::Ncurses::~Ncurses()
{
    endwin();
    wclear(stdscr);
}

extern "C" arcade::IDisplayModule *createGraphLib()
{
        return (new arcade::Ncurses());
}