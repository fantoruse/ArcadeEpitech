/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by theo,
*/

#pragma once

#include <string>
#include <array>

namespace arcade {
    enum colors_e {
        WHITE,
        BLACK,
        GREEN,
        RED,
        BLUE,
        CYAN,
        MAGENTA,
        YELLOW,
        NONE
    };

    enum type_e {
        SPRITE,
        SHAPE,
        TEXT,
        NO_TYPE
    };

    class IDrawable {
    public:
        virtual ~IDrawable() = default;
        virtual const std::string &getString() const = 0;
        virtual type_e getType() const = 0;
        virtual size_t getSize() const = 0;
        virtual colors_e getColor() const = 0;
    };
}