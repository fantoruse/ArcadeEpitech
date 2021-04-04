/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#pragma once

#include <vector>
#include <memory>
#include "Graphic/IDrawable.hpp"

namespace arcade {
    class IObject {
    public:
        virtual ~IObject() = default;
        virtual const std::pair<int,int> getPosition() const = 0;
        virtual const std::vector<IDrawable*> getDrawables() const = 0;
        virtual const std::string getName() const = 0;
    };
}