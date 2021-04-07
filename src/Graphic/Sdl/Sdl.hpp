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
        void draw(std::vector<std::shared_ptr<IDrawable>> drawable, std::pair<int, int> position, std::string name) override;
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
    {SDLK_s, arcade::NEXT},
    {SDLK_q, arcade::PREV},
    {SDLK_t, arcade::CLOSE},
};

static const std::map<arcade::colors_e, SDL_Color> COLORS = {
        {arcade::WHITE,   SDL_Color {255,255,255}},
        {arcade::BLACK,   SDL_Color {0,0,0}},
        {arcade::GREEN,   SDL_Color {125,255,0}},
        {arcade::RED,     SDL_Color {250,125,125}},
        {arcade::BLUE,    SDL_Color {0,200,255}},
        {arcade::CYAN,    SDL_Color {176,224,230}},
        {arcade::MAGENTA, SDL_Color {255,20,147}},
        {arcade::YELLOW,  SDL_Color {255,255,0}},
        {arcade::NONE, SDL_Color{255, 255, 0}},
};
static const std::vector<std::string> TEXTURES = {
    "plouf.png"
};