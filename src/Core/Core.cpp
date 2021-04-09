/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Created by antoine,
*/
#include <fstream>
#include <iostream>
#include <filesystem>
#include "Core/Core.hpp"
#include "LoadLib/LoadLib.hpp"
#include "Error/Error.hpp"
#include <chrono>
#include "Game/Object/IObject.hpp"

namespace arcade {

    Core::Core() {
    }

    void Core::getTypes(const std::string &arg, LoadLib &ldb) {
        std::string tmp;
        for (auto &p: std::filesystem::directory_iterator("./lib")) {
            try {
                tmp = p.path();
                if (tmp.erase(0,6) == arg)
                    continue;
                ldb.initHandler(p.path());
                auto libs = ldb.loadingLib<std::string()>("getType")();
                if (libs == "graph") {
                    std::cout << p.path() << "\n";
                    OpenLibsInLibs(ldb, p.path());
                } else if (libs == "game") {
                    std::cout << p.path() << "\n";
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
            std::string tmp;
            auto libs = ldb.loadingLib<IGame *(void)>("getGame")();
            tmp = name;
            tmp.erase(0, 6);
            _loadGames.push_back(std::pair<std::string, IGame *>(tmp, libs));
        } catch (const std::runtime_error &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void Core::OpenFirstLibs(std::string arg) {
        LoadLib ldb;
        try {
            ldb.initHandler(arg);
            auto libs = ldb.loadingLib<IDisplayModule *(void)>("createGraphLib")();
            arg.erase(0, 6);
            _actualLibs = arg;
            _loadLibs.push_back(std::pair<std::string, IDisplayModule *>(arg, libs));
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
            std::string tmp;
            auto libs = ldb.loadingLib<IDisplayModule *(void)>("createGraphLib")();
            tmp = name;
            tmp.erase(0, 6);
            _loadLibs.push_back(std::pair<std::string, IDisplayModule *>(tmp, libs));
        } catch (const std::runtime_error &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void Core::game(IGame *gaming,  events_e event, IDisplayModule *libs) {
        auto k = gaming->play(event);
        libs->clearWin();
        libs->getName();
        std::string s = "bite";
        for (auto n : k)
            libs->draw(n.get()->getDrawables(), n.get()->getPosition(),s);
        if (gaming->isLost())
            std::cout << "LOOOSE" << std::endl;
        libs->refreshWin();
    }

    void Core::gameLoop() {
        int a = 0;

        for (long unsigned int i = 0; i != _loadLibs.size(); i++) {
            if (_loadLibs[i].first == _actualLibs)
                break;
        }
        auto gaming = _loadGames[0].second;
        auto libs = _loadLibs[0].second;
        libs->init();
        while (1) {
            arcade::events_e event = libs->pollEvent();
            if (event == arcade::CLOSE) {
                libs->destroy();
                break;
            }
            this->game(gaming, event, libs);

            if (event == arcade::PREV) {
                a--;
              //  std::cout << i << "\n";
                libs->destroy();
                libs = _loadLibs[a % _loadLibs.size()].second;
                libs->init();
            }
            if (event == arcade::NEXT) {
                a++;
                //std::cout << a << "\n";
                libs->destroy();
                libs = _loadLibs[a % _loadLibs.size()].second;
              //  std::cout << a << " modulo est egal a " <<  (a % _loadLibs.size()) << "\n";
                libs->init();
            }
        }
    }

}
