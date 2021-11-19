#ifndef STATE_HPP
#define STATE_HPP
#include <vector>
#include "Person.hpp"

class State{
    private:
        std::string name;
        double MeanYearlySalary;
        double MeanWeeklyHours;
        double MeanReportedRent;
        double MeanGroceryCost;
        double MeanTaxContribution;
        double PercentUnemployed;
        std::vector<Person> citizens;
    public:
        explicit State();
        explicit State(std::string name);
        void AddCitizen(Person citizen){this->citizens.push_back(citizen);}
};



#endif