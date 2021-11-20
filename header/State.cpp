#include "state.hpp"

//Default constructor to represent uninitalized object
State::State(){
    this->name = "";
    this->MeanGroceryCost = 0;
    this->MeanYearlySalary = 0;
    this->PercentUnemployed = 0;
    this->MeanTaxContribution = 0;
    this->MeanWeeklyHours = 0;
    this->MeanReportedRent = 0;
}

State::State(std::string name){
    this->name = name;
    this->MeanGroceryCost = 0;
    this->MeanYearlySalary = 0;
    this->PercentUnemployed = 0;
    this->MeanTaxContribution = 0;
    this->MeanWeeklyHours = 0;
    this->MeanReportedRent = 0;
}

//Loop over all citizens and output their information
std::string State::printInformation(){
    std::ostringstream data;

    for(size_t i =0; i < this->citizens.size(); i++){
        data << this->citizens.at(i).printInformation();
    }

    return data.str();
}