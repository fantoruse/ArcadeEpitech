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
        virtual std::pair<float,float> getPosition() const = 0;
        virtual const std::vector<std::shared_ptr<IDrawable>> getDrawables() const = 0;
        virtual std::string getName() const = 0;
    };
}