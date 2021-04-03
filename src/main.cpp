/*
** EPITECH PROJECT, 2021
** main.cpp.c
** File description:
** main.cpp.c
*/

#include <iostream>
#include "dynamicFile.hpp"
#include "Error/Error.hpp"
#include "LoadLib/LoadLib.hpp"
#include "InterfaceGame/Iinterface.hpp"
#include "Core/Core.hpp"

int main(int argc, char **argv) {
    /*if (argc != 2)
        return 84;*/
    DynamicFile a;
    LoadLib b;
    arcade::Core oli;
    try {
   //     a.VerifyArg(argv[1]);
        /*b.initHandler(std::string(argv[1]));
        auto z = b.loadingLib<Iinterface *(void)>("toto")();
        z->draw();*/
        oli.OpenGame("./src/Game/arcade_nibbler.so");
    } catch (const Error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    } /*catch (...)
    {
        return 84;
    }*/
    return 0;
}