/*
** EPITECH PROJECT, 2021
** Sdl.hpp.h
** File description:
** Sdl.hpp.h
*/

#pragma once

#include <SDL2/SDL.h>
#include <vector>
//#include <SDL2/SDL_ttf.h>
#include <map>
#include "../ADisplayModule.hpp"

namespace arcade {
    class SDLModule: public arcade::ADisplayModule {
    public:
        SDLModule();
        ~SDLModule() override;

        void init() override;
        void destroy() override;
        void draw(std::vector<std::shared_ptr<IDrawable>> drawable, std::pair<int, int> position, std::string &name) override;
        events_e pollEvent() override;
        void load(std::vector<std::shared_ptr<IDrawable>> drawable, std::string &name) override;
        void refreshWin() override;
        void clearWin() override;

    private:
        SDL_Renderer *_renderer;
        SDL_Window *_window;
        bool _status;
        std::map<std::string, SDL_Texture *> _textures;
        std::map<std::string, SDL_Rect> _sprites;
        std::map<std::string, SDL_Rect> _shapes;
    };
}

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