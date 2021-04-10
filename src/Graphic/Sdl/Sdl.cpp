/*
** EPITECH PROJECT, 2021
** Sdl.cpp.c
** File description:
** Sdl.cpp.c
*/

#include "Sdl.hpp"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <iostream>

arcade::SDLModule::SDLModule() : arcade::ADisplayModule("SDL"), _renderer(), _window(), _status(true){
}

void arcade::SDLModule::init() {

    TTF_Init();
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return;
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1980, 1080,
                               SDL_WINDOW_SHOWN);
    if (!_window)
        return;
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    SDL_SetRenderDrawColor(_renderer, 0, 50, 50, 50);
}

void arcade::SDLModule::destroy() {
    SDL_DestroyWindow(_window);
    //SDL_DestroyRenderer(_renderer);
    TTF_Quit();
    SDL_Quit();
}

void arcade::SDLModule::draw(std::vector<std::shared_ptr<IDrawable>> drawable, std::pair<int, int> position,
                             [[maybe_unused]] const std::string &name) {

    SDL_Texture* images = IMG_LoadTexture(_renderer,drawable[0]->getString().c_str());
    if(drawable[0]->getType() == arcade::SPRITE && images) {
        SDL_Rect Message_rect;
        Message_rect.x = position.second  * (drawable[0]->getSize());
        Message_rect.y = position.first * (drawable[0]->getSize());
        Message_rect.w = drawable[0]->getSize();
        Message_rect.h = drawable[0]->getSize();
        SDL_RenderCopy(_renderer, images, NULL, &Message_rect);
        SDL_DestroyTexture(images);
    }
    else if (drawable[1]->getType() == arcade::SHAPE) {
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
    } else {
        TTF_Font *font = TTF_OpenFont("./resources/font.ttf", 100);
        SDL_Surface *msg = TTF_RenderText_Solid(font, drawable[2]->getString().c_str(), {255, 255, 255, 0});
        SDL_Texture *createTFS = SDL_CreateTextureFromSurface(_renderer, msg);
        SDL_Rect Message_rect;
        Message_rect.x = 1400;
        Message_rect.y = 500;
        Message_rect.w = 200;
        Message_rect.h = 100;
        SDL_RenderCopy(_renderer, createTFS, NULL, &Message_rect);
        TTF_CloseFont(font);
        SDL_FreeSurface(msg);
        SDL_DestroyTexture(createTFS);
    }
}

arcade::events_e arcade::SDLModule::pollEvent() {
    SDL_Event event = {0};
    static bool isPressed = false;
    static SDL_Keycode keyTouch = SDLK_x;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return arcade::CLOSE;
        }
        if (event.type == SDL_KEYDOWN) {
            isPressed = true;
            keyTouch = event.key.keysym.sym;
        }
        if (event.type == SDL_KEYUP && isPressed && keyTouch == event.key.keysym.sym) {
            for (auto &&i : KEYS) {
                if (event.key.keysym.sym == i.first)
                    return i.second;
            }
        }
    }
    return arcade::NOTHING;
}

void arcade::SDLModule::load([[maybe_unused]] std::vector<std::shared_ptr<IDrawable>> drawable,
                             [[maybe_unused]] const std::string &name) {
}

arcade::SDLModule::~SDLModule() {
}

void arcade::SDLModule::refreshWin() {
    SDL_RenderPresent(_renderer);
}

void arcade::SDLModule::clearWin() {
    SDL_RenderClear(_renderer);
}

std::string arcade::SDLModule::getForm( [[maybe_unused]] std::string str) {
    return "toto";
}

void arcade::SDLModule::drawText([[maybe_unused]] const std::string &string, [[maybe_unused]] std::pair<int, int> position) {}

extern "C" arcade::IDisplayModule *createGraphLib() {
    return (new arcade::SDLModule());
}

extern "C" std::string getType() {
    return "graph";
}