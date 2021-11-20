#include "Person.hpp"

Person::Person(){
    //Standard for non-initalized person
    
    this->country = "";
    this->YearlyPay = 0;
    this->WeeklyHours = 0;
    this->HourlyWage = 0;
    this->YearsExperience = 0;

    //E is standard for non-initalized person
    this->unemployedStatus = 'E';
    this->reportedRent = 0;
    this->expectedTaxContribution = 0;
    this->GroceryCost = 0;
}

Person::Person(std::string country, int YearlyPay, int WeeklyHours, double HourlyWage, double YearsExperience,
        char unemployedStatus, int reportedRent, int expectedTaxContribution, int GroceryCost){
            this->country = country;
            this->YearlyPay = YearlyPay;
            this->WeeklyHours = WeeklyHours;
            this->HourlyWage = HourlyWage;
            this->YearsExperience = YearsExperience;
            this->unemployedStatus = unemployedStatus;
            this->reportedRent = reportedRent;
            this->expectedTaxContribution = expectedTaxContribution;
            this->GroceryCost = GroceryCost;
        }

std::string Person::printInformation(){
    std::ostringstream output;

    output << this->country << " " << this->YearlyPay << " " << this->WeeklyHours << " " << this->HourlyWage << " "
           << this->YearsExperience << " " << this->unemployedStatus << " " << this->reportedRent << " " << this->expectedTaxContribution
           << " " << this->GroceryCost << std::endl; 


    return output.str();
}