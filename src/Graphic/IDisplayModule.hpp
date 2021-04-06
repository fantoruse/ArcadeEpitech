/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#pragma once

#include <memory>
#include <utility>
#include <vector>
#include "IDrawable.hpp"

namespace arcade {

    enum events_e {
        CLOSE,
        UP,
        DOWN,
        LEFT,
        RIGHT,
        SPACE,
        ESCAPE,
        NEXT,
        PREV,
        NOTHING
    };

    class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;
    
        virtual std::string getName() const = 0;
        virtual void init() = 0;
        virtual void destroy() = 0;
        virtual void clearWin() = 0;
        virtual void refreshWin() = 0;
        virtual void draw(std::vector<std::shared_ptr<IDrawable>> drawable, std::pair<int, int> position, std::string name) = 0;
        virtual void load(std::vector<std::shared_ptr<IDrawable>> drawable, std::string &name) = 0;
        virtual events_e pollEvent() = 0;
    };
}

extern "C" arcade::IDisplayModule *createGraphLib();