/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Created by theo,
*/

#pragma once

#include "IObject.hpp"

namespace arcade {
    class StaticObject : public IObject {
        public:
            StaticObject(const std::string &, const std::vector<std::shared_ptr<IDrawable>>&, std::pair<int,int>);
            ~StaticObject() = default;

            void setDrawables(std::vector<std::shared_ptr<IDrawable>>);
            void setName(std::string &);
            const std::pair<int,int> getPosition() const override;
            const std::vector<std::shared_ptr<IDrawable>> getDrawables() const override;
            const std::string getName() const override;

        protected:
            std::string _name;
            std::vector<std::shared_ptr<IDrawable>> _drawables;
            std::pair<int, int> _position;
    };
}