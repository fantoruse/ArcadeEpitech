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
#include "Game/Object/IObject.hpp"
#include "Game/IGame.hpp"

namespace arcade {

    Core::Core() {
        this->_loadLibs;
        this->_actualLibs;
    }

    void Core::OpenGame(std::string path) {
        LoadLib ldb;

        ldb.initHandler(path);
        std::cout << "bite\n" << "\n";
        auto libs = ldb.loadingLib<IDisplayModule *(void)>("createGraphLib")();
        libs->init();
        // while(1) {
        //     if (libs->pollEvent() == arcade::CLOSE)
        //         break;
        // }
        //   libs->getName();
        //    auto tmp = libs->play();
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
                    if (i > _loadLibs.size())
                        i = 0;
                    _actualLibs = _loadLibs[i].first;
                }
            }
        }
        if (event == arcade::PREV) {
            for (long unsigned int i = 0; i != _loadLibs.size(); i++) {
                if (_loadLibs[i].first == _actualLibs) {
                    if (i == 0)
                        i = _loadLibs.size();
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
            auto libs = _loadLibs[0].second;
            libs->init();
            while (1) {
                auto tmp = _actualLibs;
                if (libs->pollEvent() == arcade::CLOSE)
                    break;
                libs->refreshWin();
                libs->clearWin();
                libs->getName();
                switchLibs(libs->pollEvent());
                if (tmp != _actualLibs)
                    for (; i != _loadLibs.size(); i++) {
                        if (_loadLibs[i].first == _actualLibs) {
                            libs->destroy();
                            libs = _loadLibs[i].second;
                            libs->init();
                            break;
                        }
                    }
        }
    }
}