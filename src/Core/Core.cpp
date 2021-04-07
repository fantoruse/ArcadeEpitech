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
#include <chrono>
#include "Game/Object/IObject.hpp"

namespace arcade {

    Core::Core() {
        this->_loadLibs;
        this->_actualLibs;
        this->_loadGames;
        this->_actualGames;
    }

    void Core::OpenGame() {
        LoadLib ldb;
        std::string tmp;
        for (auto &p: std::filesystem::directory_iterator("./games")) {
            ldb.initHandler(p.path());
            auto libs = ldb.loadingLib<IGame *(void)>("GetGame")();
            tmp = p.path();
            tmp.erase(0, 12);
            _loadGames.push_back(std::pair<std::string, IGame *>(tmp, libs));
            //  std::cout << tmp << "\n";
        }
        std::cout << "name game === " << _loadGames[0].first << "\n";
    }

    void Core::OpenFirstLibs(std::string arg) {
        LoadLib ldb;
        ldb.initHandler(arg);
        auto libs = ldb.loadingLib<IDisplayModule *(void)>("createGraphLib")();
        arg.erase(0, 6);
        _actualLibs = arg;
        _loadLibs.push_back(std::pair<std::string, IDisplayModule *>(arg, libs));
    }

    void Core::OpenLibsInLibs(std::string arg) {
        LoadLib ldb;
        std::string tmp;
        for (auto &p: std::filesystem::directory_iterator("./lib")) {
            if (arg == p.path())
                continue;
            ldb.initHandler(p.path());
            auto libs = ldb.loadingLib<IDisplayModule *(void)>("createGraphLib")();
            tmp = p.path();
            tmp.erase(0, 6);
            _loadLibs.push_back(std::pair<std::string, IDisplayModule *>(tmp, libs));
            std::cout << tmp << "\n";
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
                    //std::cout << _loadLibs.size() << "\n";
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
        while (1) {
            //std::chrono::seconds sec(1);
            auto tmp = _actualLibs;
            if (libs->pollEvent() == arcade::CLOSE) {
                break;
            }
            if (std::chrono::duration_cast<std::chrono::seconds>(end - start) >= std::chrono::milliseconds (500)) {
                libs->clearWin();
                auto k = gaming->play(arcade::UP);
                start = std::chrono::steady_clock::now();
                libs->getName();
                std::string s = "bite";
                for (auto n : k) {
                    libs->draw(n.get()->getDrawables(), n.get()->getPosition(), s);
                }
                libs->refreshWin();
            }
            end = std::chrono::steady_clock::now();
            switchLibs(libs->pollEvent());
            if (tmp != _actualLibs)
                for (long unsigned int a = 0; a != _loadLibs.size(); a++) {
                    if (_loadLibs[a].first == _actualLibs) {
                        libs->destroy();
                        libs = _loadLibs[a].second;
                        libs->init();
                        break;
                    }
                }
        }
    }
}
