/*
** EPITECH PROJECT, 2021
** Sdl.hpp.h
** File description:
** Sdl.hpp.h
*/

#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <SDL2/SDL_ttf.h>
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
    {SDLK_n, arcade::NEXT},
    {SDLK_p, arcade::PREV},
    {SDLK_q, arcade::CLOSE},
    {SDLK_r, arcade::RESTART},
    {SDLK_g, arcade::PREV_GAME},
    {SDLK_h, arcade::NEXT_GAME}
};

static const std::map<arcade::colors_e, SDL_Color> COLORS = {
        {arcade::WHITE,   {(Uint8)255,(Uint8)255,(Uint8)255,(Uint8)255}},
        {arcade::BLACK,   {(Uint8)0,(Uint8)0,(Uint8)0,(Uint8)255}},
        {arcade::GREEN,   {(Uint8)125,(Uint8)255,(Uint8)0,(Uint8)255}},
        {arcade::RED,     {(Uint8)250,(Uint8)125,(Uint8)125,(Uint8)255}},
        {arcade::BLUE,    {(Uint8)0,(Uint8)200,(Uint8)255,(Uint8)255}},
        {arcade::CYAN,    {(Uint8)176,(Uint8)224,(Uint8)230,(Uint8)255}},
        {arcade::MAGENTA, {(Uint8)255,(Uint8)20,(Uint8)147,(Uint8)255}},
        {arcade::YELLOW,  {(Uint8)255,(Uint8)255,(Uint8)0,(Uint8)255}},
        {arcade::NONE,{(Uint8)255, (Uint8)255, (Uint8)0, (Uint8)255}},
};

static const std::vector<std::string> TEXTURES = {
    "plouf.png"
};