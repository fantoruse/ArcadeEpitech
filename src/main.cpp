/*
** EPITECH PROJECT, 2021
** main.cpp.c
** File description:
** main.cpp.c
*/

#include "dynamicFile.hpp"
#include "Error/Error.hpp"
#include <iostream>
#include "LoadLib/LoadLib.hpp"

int main(int argc, char **argv) {
    if (argc != 2)
        return 84;
    DynamicFile a;
    LoadLib b;
    try {
   //     a.VerifyArg(argv[1]);
        b.LoadingLib(argv[1]);
    } catch (const Error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}