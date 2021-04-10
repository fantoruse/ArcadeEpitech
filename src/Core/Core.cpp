/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/

#include <iostream>
#include <filesystem>
#include "Core/Core.hpp"
#include "LoadLib/LoadLib.hpp"
#include "Error/Error.hpp"

namespace arcade {

    void Core::getTypes(const std::string &arg, LoadLib &ldb) {
        std::string tmp;
        for (auto &p: std::filesystem::directory_iterator("./lib")) {
            try {
                tmp = p.path();
                if (tmp == arg)
                    continue;
                ldb.initHandler(p.path());
                auto libs = ldb.loadingLib<std::string()>("getType")();
                if (libs == "graph") {
                    OpenLibsInLibs(ldb, p.path());
                } else if (libs == "game") {
                    OpenGame(ldb, p.path());
                }
            } catch (const std::runtime_error &e) {
                std::cerr << e.what() << std::endl;
                continue;
            }
        }
    }

    void Core::OpenGame(const LoadLib &ldb, const std::string &name) {
        try {
            auto libs = ldb.loadingLib<IGame *(void)>("getGame")();
            _loadGames.push_back(std::pair<std::string, std::shared_ptr<IGame>>(name, libs));
        } catch (const std::runtime_error &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void Core::OpenFirstLibs(std::string &arg, LoadLib &ldb) {
        try {
            ldb.initHandler(arg);
            auto libs = ldb.loadingLib<IDisplayModule *(void)>("createGraphLib")();
            _loadLibs.push_back(std::pair<std::string, std::shared_ptr<IDisplayModule>>(arg, libs));
            getTypes(arg, ldb);
        } catch (const std::runtime_error &e) {
            std::cerr << e.what() << std::endl;
            throw std::exception();
        }
        if (_loadGames.empty())
            throw Error("No games");
    }

    void Core::OpenLibsInLibs(const LoadLib &ldb, const std::string &name) {
        try {
            auto libs = ldb.loadingLib<IDisplayModule *(void)>("createGraphLib")();
            _loadLibs.push_back(std::pair<std::string, std::shared_ptr<IDisplayModule>>(name, libs));
        } catch (const std::runtime_error &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void Core::game(std::shared_ptr<IGame> &gaming, events_e event, std::shared_ptr<IDisplayModule> &libs) {
        auto k = gaming->play(event);
        libs->clearWin();
        libs->getName();
        std::string s = "tmp";
        for (auto n : k)
            libs->draw(n.get()->getDrawables(), n.get()->getPosition(), s);
        libs->refreshWin();
    }

    void Core::gameLoop(LoadLib &ldb) {
        int a = 0;
        int y = 0;

        _loadLibs[0].second->init();
        arcade::events_e event = arcade::NOTHING;
        while (1) {
            event = arcade::NOTHING;
            event = _loadLibs[a % _loadLibs.size()].second->pollEvent();
            if (event == arcade::CLOSE || _loadGames[y % _loadGames.size()].second->isLost()) {
                _loadLibs[a % _loadLibs.size()].second->destroy();
                break;
            }
            this->game(_loadGames[y % _loadGames.size()].second, event, _loadLibs[a % _loadLibs.size()].second);
            if (event == arcade::PREV) {
                _loadLibs[a % _loadLibs.size()].second->destroy();
                a -= 1;
                _loadLibs[a % _loadLibs.size()].second->init();
            }
            if (event == arcade::NEXT) {
                _loadLibs[a % _loadLibs.size()].second->destroy();
                a += 1;
                _loadLibs[a % _loadLibs.size()].second->init();
            }
            if (event == arcade::NEXT_GAME)
                y += 1;
            if (event == arcade::PREV_GAME)
                y -=1;
        }
    }

  //  Core::~Core() {}
}