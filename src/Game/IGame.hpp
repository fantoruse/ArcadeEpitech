/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#pragma once

#include <memory>
#include <vector>
#include "Object/IObject.hpp"
#include "Graphic/IDisplayModule.hpp"

namespace arcade {
class IGame {
public:
    virtual ~IGame() = default;
    virtual const std::vector<std::shared_ptr<IObject>> play(arcade::events_e
    ) = 0;
    virtual const std::string &getName() const = 0;
    virtual bool isLost() = 0;
};
}

extern "C" std::string getType();

