/*
** EPITECH PROJECT, 2021
** LoadLib.hpp.h
** File description:
** LoadLib.hpp.h
*/

#ifndef B_OOP_400_PAR_4_1_ARCADE_CLEMENT1_RUAT_LOADLIB_HPP
#define B_OOP_400_PAR_4_1_ARCADE_CLEMENT1_RUAT_LOADLIB_HPP

#include <string>

class LoadLib {
public:
    LoadLib() = default;
    ~LoadLib() = default;
    LoadLib *LoadingLib(std::string files);
};

#endif //B_OOP_400_PAR_4_1_ARCADE_CLEMENT1_RUAT_LOADLIB_HPP
