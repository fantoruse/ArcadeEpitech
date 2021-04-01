/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#ifndef ARCADE_IOBJECT_HPP
#define ARCADE_IOBJECT_HPP

#include <vector>
#include "Graphic/IDrawable.hpp"

namespace arcade {
class IObject {
public:
    virtual ~IObject() = default;
    virtual std::pair<int,int> getPosition() const = 0;
    virtual IDrawable &getDrawable() const = 0;
    virtual std::string getName() const = 0;

protected:
private:
};
}

#endif //ARCADE_IOBJECT_HPP
