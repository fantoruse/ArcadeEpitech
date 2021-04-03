/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include "ADisplayModule.hpp"

namespace arcade {
class SFMLModule: public arcade::ADisplayModule
{
public:
    SFMLModule();
    ~SFMLModule() = default;

    void init() override;
    void destroy() override;
    void draw(Drawable drawable, std::pair<float, float> position, int size) override;
    events_e pollEvent() override;
    void load() override;
        
private:
    sf::RenderWindow _window;
    std::map<std::string, sf::Texture> _textures;
    std::map<std::string, sf::Sprite> _sprites;
    std::map<std::string, sf::Shape> _shapes;

    static const std::vector<std::string> TEXTURES = {
        "plouf.png"
    };

    static const std::vector<std::pair<sf::Keyboard::Key, arcade::events_e>> KEYS = {
        {sf::Keyboard::Escape, arcade::ESCAPE},
        {sf::Keyboard::Up, arcade::UP},
        {sf::Keyboard::Down, arcade::DOWN},
        {sf::Keyboard::Left, arcade::LEFT},
        {sf::Keyboard::Right, arcade::RIGHT},
        {sf::Keyboard::Space, arcade::SPACE},
    };
};
}
