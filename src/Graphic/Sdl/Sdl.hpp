/*
** EPITECH PROJECT, 2021
** Sdl.hpp.h
** File description:
** Sdl.hpp.h
*/

#pragma once

#include <SDL2/SDL.h>
#include "Graphic/ADisplayModule.hpp"
#include <vector>
//#include <SDL2/SDL_ttf.h>
#include <map>

namespace arcade {
    class SDLModule: public arcade::ADisplayModule {
    public:
        SDLModule();
        ~SDLModule() = default;

        void init() override;
        void destroy() override;
        void draw(Drawable drawable, std::pair<float, float> position, int size) override;
        events_e pollEvent() override;
        void load() override;

    private:
        SDL_Renderer *_renderer;
        SDL_Window *_window;
        bool _status;
        std::map<std::string, SDL_Texture> _textures;
        std::map<std::string, SDL_Rect> _sprites;
        std::map<std::string, SDL_Rect> _shapes;
    };
    static const std::vector<std::pair<SDL_Keycode, arcade::events_e>> KEYS = {
        {SDLK_ESCAPE, arcade::ESCAPE},
        {SDLK_UP, arcade::UP},
        {SDLK_DOWN, arcade::DOWN},
        {SDLK_LEFT, arcade::LEFT},
        {SDLK_RIGHT, arcade::RIGHT},
        {SDLK_SPACE, arcade::SPACE},
    };

    static const std::vector<std::string> TEXTURES = {
        "plouf.png"
    };
}