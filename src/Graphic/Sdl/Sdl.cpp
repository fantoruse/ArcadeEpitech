/*
** EPITECH PROJECT, 2021
** Sdl.cpp.c
** File description:
** Sdl.cpp.c
*/

#include "Sdl.hpp"
#include "Error/Error.hpp"
#include <SDL/SDL_image.h>

arcade::SDLModule::SDLModule() : arcade::ADisplayModule("SDL") {}

void arcade::SDLModule::init() {
    // int renderedFlags = SDL_RENDERER_ACCELERATED;
    int windowFlags = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw Error("can't open SDL window");
    _window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080,
                               SDL_WINDOW_BORDERLESS);
    if (!_window)
        throw Error("Erro can't open a sdl window");
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);

    if (_status == false) {
        SDL_DestroyWindow(_window);
        SDL_QUIT;
        }
}

/*
    CLEAR =     SDL_RenderClear(_renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
*/

void arcade::SDLModule::destroy() {
}

void arcade::SDLModule::draw(Drawable drawable, std::pair<float, float> position, int size) {
    //rectangle
    SDL_Rect rectangle;
    rectangle.x = position.first;
    rectangle.y = position.second;
    rectangle.h = 100 * size;
    rectangle.w = 100 * size;
    
    SDL_RenderDrawRect(_renderer, &rectangle);
    SDL_SetRenderDrawColor(_renderer, 100, 100, 100, 100);
    SDL_RenderPresent(_renderer);

    //sprite

}

arcade::events_e arcade::SDLModule::pollEvent() {
    SDL_Event event;

    if (SDL_PollEvent(&event)) 
        if (event.type == SDL_QUIT) {
            _status = false;
        } 
    else
        for (auto &&i : KEYS)
            if (event.key.keysym.sym == i.first)   
                return i.second;
}

void arcade::SDLModule::load()
{
    SDL_Texture *texture;

    SDL_Surface *surface = IMG_Load("bite");
    texture = SDL_CreateTextureFromSurface(_renderer, surface);
    SDL_Rect rect{50,50,100,100};
    SDL_RenderCopy(_renderer,texture,NULL, &rect);
    SDL_RenderPresent(_renderer);
}