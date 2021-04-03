/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#pragma once

#include <string>
#include "IDisplayModule.hpp"

namespace arcade {
class ADisplayModule : public arcade::IDisplayModule {
public:
    ADisplayModule(const std::string &name);
    virtual const std::string getName() const;

protected:
    std::string _name;
};
}
