#ifndef STATE_HPP
#define STATE_HPP
#include <vector>
#include "Person.hpp"
#include "Stats.hpp"

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

        void SetName(std::string name) {this->name = name;}
        std::string GetName() const {return this->name;}

        double GetMeanSalary(){return Stats::CalculateMean(citizens, 1);}
        double GetMeanHours() {return Stats::CalculateMean(citizens, 2);}
        double GetMeanRent() {return Stats::CalculateMean(citizens, 3);}
        double GetMeanGrocery(){return Stats::CalculateMean(citizens,4);}
        double GetMeanTax(){return Stats::CalculateMean(citizens,5);}
        double GetUnemployed(){return Stats::CalculateMean(citizens,6);}

        std::string printInformation();
};



#endif