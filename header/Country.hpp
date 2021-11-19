#ifndef COUNTRY_HPP
#define COUNTRY_HPP

#include "State.hpp"

class Country{
    private:
        //Only applicable for U.S
        std::vector<State> states;

        //Non-U.S countries
        std::vector<Person> citizens;

};




#endif