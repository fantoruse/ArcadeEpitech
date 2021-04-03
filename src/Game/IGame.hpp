/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#ifndef ARCADE_IGAME_HPP
#define ARCADE_IGAME_HPP

#include <memory>
#include <vector>
#include "IObject.hpp"

namespace arcade {
    class IGame {
    public:
        virtual std::vector <std::shared_ptr<IObject>> play() const = 0;
        virtual const std::string getName() const = 0;
    };
}

#endif //ARCADE_IGAME_HPP
