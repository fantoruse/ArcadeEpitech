/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#include "SFML/SfmlModule.hpp"

arcade::SFMLModule::SFMLModule(): arcade::ADisplayModule("SFML")
{
}
void arcade::SFMLModule::init()
{
    _window.create(sf::VideoMode(1920, 1080), "Arcade");
}
void arcade::SFMLModule::destroy()
{
}
void arcade::SFMLModule::draw(Drawable drawable, std::pair<float, float> position, int size)
{
    auto SpriteToDisplay = _sprites.find(drawable.getName());
    sf::Shape ShapeToDisplay = _shapes[drawable.getName()];

    if (SpriteToDisplay == _sprites.crend()) {
        SpriteToDisplay.setPosition(position.first, position.second);
    } else {

    }
}
arcade::events_e arcade::SFMLModule::pollEvent()
{
    sf::Event event;

    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            _window.close();
        else if (event.type == sf::Event::KeyPressed)
            for (auto &&i : KEYS)
                if (event.key.code == i.first)
                    return i.second;
    }
    return arcade::NOTHING;
}

void arcade::SFMLModule::load()
{
    sf::Texture loading;

    for (auto &&i : TEXTURES)
        _textures[i].loadFromFile(i);
}
