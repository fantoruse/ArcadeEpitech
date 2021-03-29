/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#ifndef ARCADE_IGRAPHIC_HPP
#define ARCADE_IGRAPHIC_HPP

#include <memory>

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
    virtual void draw(Drawable drawable, std::pair<int, int> position, int size) = 0;
    virtual void init() = 0;
    virtual void destroy() = 0;
    virtual events_e pollEvent() = 0;
    virtual void load() = 0;
    virtual std::unique_ptr<IDisplayModule> createGraphLib() = 0;
};
}

#endif //ARCADE_IGRAPHIC_HPP
