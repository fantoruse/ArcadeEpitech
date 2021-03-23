/*
** EPITECH PROJECT, 2021
** Error.cpp.c
** File description:
** Error.cpp.c
*/

#include "Error/Error.hpp"

Error::Error(const std::string txt) throw() {
    _description = txt;
}

Error::~Error() throw() {}

const char * Error::what() const noexcept {
    return _description.c_str();
}