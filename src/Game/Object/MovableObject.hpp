/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Created by theo,
*/

#pragma once

#include "StaticObject.hpp"

namespace arcade {
class MovableObject : public StaticObject {
public:
    MovableObject(const std::string &, std::vector<std::shared_ptr<IDrawable>>,
        std::pair<int, int>
    );
    ~MovableObject() = default;

    void setPosition(std::pair<int, int>);
};
}