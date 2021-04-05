/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Created by theo,
*/

#pragma once

#include <string>
#include <vector>
#include "IDrawable.hpp"

namespace arcade {
class Drawable : public arcade::IDrawable {
public:
    Drawable(const std::string &obj = "NONE", std::size_t size = 0, arcade::type_e type = arcade::NO_TYPE, colors_e color = arcade::NONE);
    ~Drawable() override = default;

    const std::string &getString() const override;
    std::size_t getSize() const override;
    type_e getType() const override;
    colors_e getColor() const override;

protected:
    std::string _infos;
    std::size_t _size;
    arcade::type_e _type;
    colors_e _color;
};
}