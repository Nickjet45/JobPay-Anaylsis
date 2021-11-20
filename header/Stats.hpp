#ifndef STATS_HPP
#define STATS_HPP
#include <vector>
//Class made solely to consolidate mean calculation

#include "Person.hpp"

class Stats{
    public:
        static double CalculateMean(std::vector<Person> data, int meanCode);
};



#endif