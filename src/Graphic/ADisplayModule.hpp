/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#ifndef ARCADE_ADISPLAYMODULE_HPP
#define ARCADE_ADISPLAYMODULE_HPP

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

#endif //ARCADE_ADISPLAYMODULE_HPP
