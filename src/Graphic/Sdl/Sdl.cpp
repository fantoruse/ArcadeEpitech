/*
** EPITECH PROJECT, 2021
** Sdl.cpp.c
** File description:
** Sdl.cpp.c
*/

#include "Sdl.hpp"
#include <SDL2/SDL_ttf.h>
#include <iostream>

arcade::SDLModule::SDLModule() : arcade::ADisplayModule("SDL"), _renderer(), _window(), _status(true), _textures(),
                                 _sprites(), _shapes() {
}

void arcade::SDLModule::init() {

    TTF_Init();
    std::cout << "\n WINDOW IS OPEN\n";
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return;
    _window = SDL_CreateWindow("ANTOINE LE PLUS BEAU", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1980, 1080,
                               SDL_WINDOW_SHOWN);
    if (!_window)
        return;
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    SDL_SetRenderDrawColor(_renderer, 0, 50, 50, 50);
    // SDL_Delay(10);
}

void arcade::SDLModule::destroy() {
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    TTF_Quit();
    SDL_Quit();
}

void arcade::SDLModule::draw(std::vector<std::shared_ptr<IDrawable>> drawable, std::pair<int, int> position,
                             std::string name) {
    if (drawable[1]->getType() == arcade::SHAPE) {
    SDL_Rect rectangle;
    rectangle.y = position.first * (drawable[1]->getSize());
    rectangle.x = position.second * (drawable[1]->getSize());
    rectangle.h = 50;
    rectangle.w = 50;
    SDL_SetRenderDrawColor(_renderer, COLORS.at(drawable[1]->getColor()).r, COLORS.at(drawable[1]->getColor()).g,
                           COLORS.at(drawable[1]->getColor()).b, COLORS.at(drawable[1]->getColor()).a);
    SDL_RenderFillRect(_renderer, &rectangle);
    SDL_RenderDrawRect(_renderer, &rectangle);
    SDL_SetRenderDrawColor(_renderer, 0, 50, 50, 50);
        std::cout << "CACA TERMINE\n";
    } else {
        TTF_Font *font = TTF_OpenFont("./resources/font.ttf", 100);
        SDL_Surface *msg = TTF_RenderText_Solid(font, drawable[2]->getString().c_str(), {255, 255, 255, 255});
        SDL_Texture* createTFS = SDL_CreateTextureFromSurface(_renderer, msg);
        SDL_Rect Message_rect;
        Message_rect.x = 1400;
        Message_rect.y = 900;
        Message_rect.w = 100;
        Message_rect.h = 100;
        std::cout << "bite\n";
        SDL_RenderCopy(_renderer, createTFS, NULL, &Message_rect);
    }
}

arcade::events_e arcade::SDLModule::pollEvent() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return arcade::CLOSE;
        }
        for (auto &&i : KEYS)
            if (event.key.keysym.sym == i.first)
                return i.second;
    }
    return arcade::NOTHING;
}

void arcade::SDLModule::load(std::vector<std::shared_ptr<IDrawable>> drawable, std::string &name) {

}

arcade::SDLModule::~SDLModule() {

    SDL_DestroyWindow(_window);
}

void arcade::SDLModule::refreshWin() {
    SDL_RenderPresent(_renderer);
}

void arcade::SDLModule::clearWin() {
    SDL_RenderClear(_renderer);
}

extern "C" arcade::IDisplayModule *createGraphLib() {
    return (new arcade::SDLModule());
}