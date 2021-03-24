/*
** EPITECH PROJECT, 2021
** dynamicFile.cpp.c
** File description:
** dynamicFile.cpp.c
*/

#include "dynamicFile.hpp"
#include "Error/Error.hpp"
#include <iostream>

DynamicFile::DynamicFile() {}

DynamicFile::~DynamicFile() {}

void DynamicFile::VerifyArg(char *argv) const {
    std::string arguments;
    const std::string AllLibs = "arcade_ndk++.so arcade_aalib.so arcade_libcaca.so "
                          "arcade_allegro5.so arcade_xlib.so arcade_gtk+.so "
                          "arcade_sfml.so arcade_irrlicht.so arcade_opengl.so "
                          "arcade_vulkan.so arcade_qt5.so ";

    arguments.assign(argv);
    if (arguments.find("lib/") == std::string::npos && arguments.find("./libs") == std::string::npos)
        throw Error("Il n'y a pas de dossier : ./lib/");
    if (arguments.find("./lib") != std::string::npos)
        arguments.erase(0, 6);
    else
        arguments.erase(0, 4);
    if (AllLibs.find(arguments) == std::string::npos)
        throw Error("Ce ne sont pas les bonnes bibliotheque ou ce n'est pas compatible");
}