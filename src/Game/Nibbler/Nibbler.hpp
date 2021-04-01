/*
** EPITECH PROJECT, 2021
** nibler.hpp.h
** File description:
** nibler.hpp.h
*/

#ifndef B_OOP_400_PAR_4_1_ARCADE_CLEMENT1_RUAT_NIBBLER_HPP
#define B_OOP_400_PAR_4_1_ARCADE_CLEMENT1_RUAT_NIBBLER_HPP

#include <vector>
#include <string>
#include <iostream>

class Nibler
    {
public:
    Nibler();
    ~Nibler() = default;
    void AppleGenerator();
    void setSnake();
    void mouvement(int i);

private:
    std::pair<int, int> _applePosition;
    unsigned long int _score;
    std::string _name;
    std::vector<std::string> _map;
};

#endif //B_OOP_400_PAR_4_1_ARCADE_CLEMENT1_RUAT_NIBLER_HPP
