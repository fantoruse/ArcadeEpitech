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
        auto libs = ldb.loadingLib<IGame * (void)>("GetGame")();
        libs->getName();
    }

    void Core::OpenFirstLibs(std::string arg) {
        LoadLib ldb;
        ldb.initHandler(arg);
        auto libs = ldb.loadingLib<IDisplayModule * (void)>("toto")();
        arg.erase(0,6);
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
            auto libs = ldb.loadingLib<IDisplayModule * (void)>("GetLibs")();
            tmp = p.path();
            tmp.erase(0, 6);
            _loadLibs.push_back(std::pair<std::string, IDisplayModule*>(tmp, libs));for (auto $e: _loadLibs) {
           }
            std::cout << tmp << "\n";
        }
    }

    void Core::switchLibs(events_e event) {
        if (event == NEXT) {
            for (long unsigned int i = 0; i != _loadLibs.size(); i++) {
                if (_loadLibs[i].first == _actualLibs) {
                    i++;
                    if (i > _loadLibs.size())
                        i = 0;
                    _actualLibs = _loadLibs[i].first;
                }
            }
        }
        if (event == PREV) {
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
}