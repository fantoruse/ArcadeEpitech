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

    enum drawableType_e
    {
        SPRITE,
        SHAPE,
        TEXT
    };

    enum colors_e
        {
            WHITE,
            BLACK,
            GREEN,
            RED,
            BLUE,
            CYAN,
            MAGENTA,
            YELLOW
        };

    class IDrawable {
        public:
            IDrawable() = default;
            ~IDrawable() = default;

            virtual drawableType_e getType() = 0;
            virtual int getSize() = 0;
            virtual colors_e getColor() = 0;
            virtual std::array<std::string, 3> getInfo() = 0;
    };
}