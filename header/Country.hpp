#ifndef COUNTRY_HPP
#define COUNTRY_HPP

#include "State.hpp"
#include <unordered_map>

class Country{
    private:
        //Only applicable for U.S
        std::vector<State> states;
        std::unordered_map<std::string,int> stateIndex; //Speeds up data retrieval for states
        bool isUS; // For mean calculations
        //Non-U.S countries (And total U.S calculation)
        std::vector<Person> citizens;
        //both
        std::string name;
        double MeanYearlySalary;
        double MeanWeeklyHours;
        double MeanReportedRent;
        double MeanGroceryCost;
        double MeanTaxContribution;
        double PercentUnemployed;
    public:
        Country();
        Country(std::string name);

        void AddCitizen(Person citizen){}

        void SetName(std::string name) {this->name = name;}
        std::string GetName() const {return this->name;}

        double GetMeanSalary();
        double GetMeanHours();
        double GetMeanRent();
        double GetMeanGrocery();
        double GetMeanTax();
        double GetUnemployed();

        std::string printInformation();
    

};




#endif