/*
** EPITECH PROJECT, 2021
** Sdl.cpp.c
** File description:
** Sdl.cpp.c
*/

#include "Sdl.hpp"
#include "../Error/Error.hpp"

arcade::SDLModule::SDLModule() : arcade::ADisplayModule("SDL"), _renderer(), _window(), _status(true), _textures(), _sprites(), _shapes() {
}

void arcade::SDLModule::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw Error("can't open SDL window");
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080,
                               SDL_WINDOW_BORDERLESS);
    if (!_window)
        throw Error("Error can't open a sdl window");
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
}

void arcade::SDLModule::destroy() {
    SDL_DestroyWindow(_window);
}

void arcade::SDLModule::draw(std::vector<std::shared_ptr<IDrawable>> drawable, std::pair<int, int> position, std::string &name) {
    std::size_t size = drawable[1]->getSize();

    if (drawable[0]->getType() == arcade::SPRITE);
//         //sprite
//     //rectangle
    else if (drawable[1]->getType() == arcade::SHAPE) {
        SDL_Rect rectangle;
        rectangle.x = position.first;
        rectangle.y = position.second;
        rectangle.h = 100 * size;
        rectangle.w = 100 * size;
        SDL_RenderDrawRect(_renderer, &rectangle);
        SDL_SetRenderDrawColor(_renderer, 100, 100, 100, 100);
        SDL_RenderPresent(_renderer);
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
  //  SDL_Texture *texture;

//     SDL_Surface *surface = IMG_Load("bite");
//     texture = SDL_CreateTextureFromSurface(_renderer, surface);
  //  SDL_Rect rect{50, 50, 100, 100};
 //   SDL_RenderCopy(_renderer, texture, NULL, &rect);
 //   SDL_RenderPresent(_renderer);
}

arcade::SDLModule::~SDLModule() {
    SDL_DestroyWindow(_window);
}

void arcade::SDLModule::refreshWin() {
    SDL_UpdateWindowSurface(_window);
}

void arcade::SDLModule::clearWin() {
    SDL_RenderClear(_renderer);
}

extern "C" arcade::IDisplayModule *createGraphLib() {
    return (new arcade::SDLModule());
}