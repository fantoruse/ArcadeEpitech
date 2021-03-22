/*
** EPITECH PROJECT, 2021
** Error.hpp.h
** File description:
** Error.hpp.h
*/

#ifndef B_OOP_400_PAR_4_1_ARCADE_CLEMENT1_RUAT_Error_HPP
#define B_OOP_400_PAR_4_1_ARCADE_CLEMENT1_RUAT_Error_HPP

#include <exception>
#include <string>

class Error : public std::exception {
public:
    Error(const std::string txt) throw();
    virtual ~Error() throw();
    const char * what() const throw();

private:
    std::string _description;
};

#endif //B_OOP_400_PAR_4_1_ARCADE_CLEMENT1_RUAT_Error_HPP
