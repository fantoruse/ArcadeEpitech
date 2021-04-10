/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#include "SFML/SfmlModule.hpp"

arcade::SFMLModule::SFMLModule(): arcade::ADisplayModule("SFML"), _window(), _textures()
{
}
void arcade::SFMLModule::init()
{
    _window.create(sf::VideoMode(1920, 1080), "Arcade");
    _window.setMouseCursorVisible(false);
    _window.setFramerateLimit(60);
}
void arcade::SFMLModule::destroy()
{
    _window.close();
}
void arcade::SFMLModule::draw(std::vector<std::shared_ptr<IDrawable>> drawable, std::pair<int, int> position, [[maybe_unused]] const std::string &name)
{
    sf::Sprite sprite;
    sf::RectangleShape rectangle;
    sf::Text text;
    sf::Font font;
    sf::Texture texture;
    float size = static_cast<float>(drawable[1]->getSize());
    
    if (drawable[0]->getType() == arcade::SPRITE && texture.loadFromFile(drawable[0]->getString())) {
        texture.setSmooth(true);
        sprite.setTexture(texture);
        sprite.setPosition(position.second * size, position.first * size);
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
        text.setScale({static_cast<float>(drawable[2]->getSize()), static_cast<float>(drawable[2]->getSize())});
        text.setFillColor(COLORS.at(drawable[2]->getColor()));
        text.setOutlineColor(COLORS.at(drawable[2]->getColor()));
        text.setPosition(position.first + 1300, position.second + 500);
        _window.draw(text);
    }
}
arcade::events_e arcade::SFMLModule::pollEvent()
{
    sf::Event event;
    static bool pressed = false;
    static sf::Keyboard::Key key = sf::Keyboard::Key::F;

    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            return arcade::CLOSE;
        if (event.type == sf::Event::KeyPressed) {
            pressed = true;
            key = event.key.code;
        }
        if (event.type == sf::Event::KeyReleased && pressed && key == event.key.code) {
            pressed = false;
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
   // _window.close();
}

std::string arcade::SFMLModule::getForm( [[maybe_unused]] std::string str) {
    return "toto";
}

void arcade::SFMLModule::drawText([[maybe_unused]] const std::string &string, [[maybe_unused]] std::pair<float, float> position) {}

extern "C" arcade::IDisplayModule *createGraphLib()
{
    return (new arcade::SFMLModule());
}

extern "C" std::string getType() {
    return "graph";
}