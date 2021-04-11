/*
** EPITECH PROJECT, 2021
** Error.hpp.h
** File description:
** Error.hpp.h
*/

#pragma once

#include <exception>
#include <string>

class Error : public std::exception {
public:
    Error(const std::string txt) throw();
    virtual ~Error() throw();
    const char *what() const throw();

private:
    std::string _description;
};
