/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#include "SFML/SfmlModule.hpp"

arcade::SFMLModule::SFMLModule(): arcade::ADisplayModule("SFML"), _window(), _textures(), _sprites(), _shapes()
{
}
void arcade::SFMLModule::init()
{
    _window.create(sf::VideoMode(1920, 1080), "Arcade");
    _window.setMouseCursorVisible(false);
}
void arcade::SFMLModule::destroy()
{
    _window.close();
}
#include <iostream>
void arcade::SFMLModule::draw(std::vector<std::shared_ptr<IDrawable>> drawable, std::pair<int, int> position, [[maybe_unused]] std::string name)
{
    sf::Sprite sprite;
    sf::RectangleShape rectangle;
    sf::Text text;
    sf::Font font;
    float size = (float)drawable[1]->getSize();
    
    if (drawable[0]->getType() == arcade::SPRITE) {
        sprite.setTexture(_textures[drawable[0]->getString()]);
        sprite.setPosition(position.first, position.second);
        _window.draw(sprite);
    } else if (drawable[1]->getType() == arcade::SHAPE) {
        rectangle.setFillColor(COLORS.at(drawable[1]->getColor()));
        rectangle.setOutlineColor(COLORS.at(drawable[1]->getColor()));
        rectangle.setSize({size, size});
        rectangle.setPosition(position.second * size, position.first * size);
        _window.draw(rectangle);
    } else {
        font.loadFromFile("./resources/font.ttf");
        text.setFont(font);
        text.setString(drawable[2]->getString());
        text.setScale({(float)drawable[2]->getSize(), (float)drawable[2]->getSize()});
        text.setFillColor(COLORS.at(drawable[2]->getColor()));
        text.setOutlineColor(COLORS.at(drawable[2]->getColor()));
        text.setPosition(position.first, position.second);
        _window.draw(text);
    }
}
arcade::events_e arcade::SFMLModule::pollEvent()
{
    sf::Event event;

    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            return arcade::CLOSE;
        else if (event.type == sf::Event::KeyReleased) {
            for (auto i : KEYS)
                if (event.key.code == i.first)
                    return i.second;
        }
    }
    return arcade::NOTHING;
}

void arcade::SFMLModule::load([[maybe_unused]] std::vector<std::shared_ptr<IDrawable>> drawable, [[maybe_unused]] std::string &name)
{
    for (auto &&i : TEXTURES_TO_LOAD)
        _textures[i].loadFromFile(i);
}

void arcade::SFMLModule::clearWin()
{
    _window.clear();
}

void arcade::SFMLModule::refreshWin()
{
    _window.display();
}
arcade::SFMLModule::~SFMLModule()
{
    _window.close();
}

extern "C" arcade::IDisplayModule *createGraphLib()
{
    return (new arcade::SFMLModule());
}