/*
** EPITECH PROJECT, 2021
** nibler.cpp.c
** File description:
** nibler.cpp.c
*/

#include "Nibbler.hpp"
#include <cstdlib>
#include <iostream>

Nibler::Nibler(): _applePosition(0, 0), _score(0), _name("Nibbler")
{
    _map = {
        {}
    }
}

int main() {
    Nibler a;
    a.setSnake();
    while(1)
        a.mouvement(1);
}