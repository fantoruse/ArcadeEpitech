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
    class ADrawable : public arcade::IDrawable {
        public:
            void setSize(int size);
            int getSize();

        protected:
            int _size;
            std::array<std::string, 3> _infos;
    };
}