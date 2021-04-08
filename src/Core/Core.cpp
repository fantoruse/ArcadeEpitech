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

    void Core::getTypes(std::string arg) {
        LoadLib ldb;
        std::string tmp;
        for (auto &p: std::filesystem::directory_iterator("./lib")) {
            try {
                ldb.initHandler(p.path());
                auto libs = ldb.loadingLib<std::string()>("getType")();
                if (libs == "graph") {
                    std::cout << p.path() << "\n";
                    OpenLibsInLibs(ldb, p.path(), arg);
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

    void Core::OpenGame(LoadLib ldb, std::string name) {
        try {
            std::string tmp;
            auto libs = ldb.loadingLib<IGame *(void)>("getGame")();
            tmp = name;
            tmp.erase(0, 12);
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
            getTypes(arg);
        } catch (const std::runtime_error &e) {
            std::cerr << e.what() << std::endl;
            throw std::exception();
        }
        if (_loadGames.empty())
            throw Error("No games");
    }

    void Core::OpenLibsInLibs(LoadLib ldb, std::string name, std::string arg) {
        try {
            std::string tmp;
            name.erase(0,6);
            if (arg == name)  {
                return;
            }
            auto libs = ldb.loadingLib<IDisplayModule *(void)>("createGraphLib")();
            tmp = name;
            tmp.erase(0, 6);
            _loadLibs.push_back(std::pair<std::string, IDisplayModule *>(tmp, libs));
        } catch (const std::runtime_error &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void Core::switchLibs(events_e event) {
        if (event == arcade::NEXT) {
            for (long unsigned int i = 0; i != _loadLibs.size(); i++) {
                if (_loadLibs[i].first == _actualLibs) {
                    i++;
                    if (i >= _loadLibs.size())
                        i = 0;
                    _actualLibs = _loadLibs[i].first;
                }
            }
        }
        if (event == arcade::PREV) {
            for (long unsigned int i = 0; i != _loadLibs.size(); i++) {
                if (_loadLibs[i].first == _actualLibs) {
                    if (i == 0)
                        i = _loadLibs.size() - 1;
                    else
                        i--;
                    _actualLibs = _loadLibs[i].first;
                }
            }
        }
    }

    void Core::gameLoop() {
        long unsigned int i = 0;

        for (; i != _loadLibs.size(); i++) {
            if (_loadLibs[i].first == _actualLibs)
                break;
        }
        auto gaming = _loadGames[0].second;
        auto libs = _loadLibs[0].second;
        libs->init();
        auto start = std::chrono::steady_clock::now();
        auto end = std::chrono::steady_clock::now();
        i = 0;
        while (1) {
            auto tmp = _actualLibs;
            arcade::events_e event = libs->pollEvent();
            if (event == arcade::CLOSE) {
                libs->destroy();
                break;
            }
            auto k = gaming->play(event);
            //if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start) >= std::chrono::milliseconds(170)) {
                libs->clearWin();
                libs->getName();
                std::string s = "bite";
                for (auto n : k) {
                    libs->draw(n.get()->getDrawables(), n.get()->getPosition(),s);
                }
                start = std::chrono::steady_clock::now();
           // }
            end = std::chrono::steady_clock::now();
            if (gaming->isLost())
                std::cout << "LOOOSE" << std::endl;
            libs->refreshWin();

            if (event == arcade::PREV) {
                i--;
                libs->destroy();
                libs = _loadLibs[i % _loadLibs.size()].second;
                libs->init();
            }
            if (event == arcade::NEXT) {
                i++;
                libs->destroy();
                libs = _loadLibs[i % _loadLibs.size()].second;
                libs->init();
            }
            /*switchLibs(event);
            if (tmp != _actualLibs)
                for (long unsigned int a = 0; a != _loadLibs.size(); a++) {
                    if (_loadLibs[a].first == _actualLibs) {
                        libs->destroy();
                        libs = _loadLibs[a].second;
                        libs->init();
                        break;
                    }
                }*/
        }
    }

}
