#ifndef STATE_HPP
#define STATE_HPP
#include <vector>
#include "Person.hpp"

class State{
    private:
        std::string name;
        double MedianYearlySalary;
        double MedianWeeklyHours;
        double MedianReportedRent;
        double MedianGroceryCost;
        double MedianTaxContribution;
        double PercentUnemployed;
        std::vector<Person> citizens;
    public:
        explicit State();
        explicit State(std::string name);
        void AddCitizen(Person citizen){this->citizens.push_back(citizen);}
};



#endif