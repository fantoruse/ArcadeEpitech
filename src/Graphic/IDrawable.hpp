/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by theo,
*/

#pragma once

#include <string>

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
            IDrawable();
            ~IDrawable();
            virtual drawableType_e getType() const;
            virtual int getSize() const;
            virtual colors_e getColor() const;
            virtual std::string getInfo() const;
    };
}