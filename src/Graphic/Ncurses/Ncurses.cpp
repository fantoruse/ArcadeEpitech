/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Created by theo
*/

#include "Ncurses.hpp"

arcade::Ncurses() : ADisplayModule("NCURSES")
{
}

void arcade::draw (Drawable drawable, std::pair<int, int> position, int size)
{   
}

void arcade::init()
{
    initscr();
    nodelay(stdscr, true);
    cbreak();
    noecho();
    curs_set(0);
    getmaxyx(stdscr, _screen_y, _screen_x);
}

void arcade::destroy()
{
    endwin();
}

arcade::events_e arcade::pollEvent()
{

}

void arcade::load()
{

}

std::unique_ptr<IDisplayModule> arcade::createGraphLib()
{

}