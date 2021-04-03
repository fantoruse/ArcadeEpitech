/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#pragma once

#include <memory>
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
    NOTHING
};

class IDisplayModule {
public:
    virtual ~IDisplayModule() = default;

    virtual std::string getName() const = 0;
    virtual void draw(IDrawable drawable, std::pair<float, float> position, int size) = 0;
    virtual void init() = 0;
    virtual void destroy() = 0;
    virtual events_e pollEvent() = 0;
    virtual void load() = 0;
    virtual std::unique_ptr<IDisplayModule> createGraphLib() = 0;
    virtual void clear() = 0;
    virtual void refresh() = 0;
};
}
