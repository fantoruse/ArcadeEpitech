/*
** EPITECH PROJECT, 2021
** nibler.hpp.h
** File description:
** nibler.hpp.h
*/

#ifndef B_OOP_400_PAR_4_1_ARCADE_CLEMENT1_RUAT_NIBLER_HPP
#define B_OOP_400_PAR_4_1_ARCADE_CLEMENT1_RUAT_NIBLER_HPP

#include <vector>
#include <string>
#include <iostream>

class Nibler {
public:
    Nibler();
    ~Nibler();
    void AppleGenerator();
    void setSnake();
    void mouvement(int i);

protected:
    std::vector<std::pair<int, int>> _playerPosition;
    std::vector<std::pair<int, int>> _applePosition;
    bool _playerCollision;
    bool _wallCollision;
    bool _appleCollision;
    bool _launch;
    std::string _name;
    unsigned long int _score;
};

#endif //B_OOP_400_PAR_4_1_ARCADE_CLEMENT1_RUAT_NIBLER_HPP
