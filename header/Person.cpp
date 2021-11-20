#include "Person.hpp"

Person::Person(){
    //Standard for non-initalized person
    
    this->country = "";
    this->Industry = "";
    this->JobTitle = ""; 

    this->YearlyPay = 0;
    this->WeeklyHours = 0;
    this->HourlyWage = 0;
    this->YearsAtCompany = 0;
    this->YearsExperience = 0;

    //E is standard for non-initalized person
    this->unemployedStatus = 'E';
    this->reportedRent = 0;
    this->expectedTaxContribution = 0;
    this->GroceryCost = 0;
}

Person::Person(std::string country, std::string Industry, std::string JobTitle, int YearlyPay, int WeeklyHours, double HourlyWage, double YearsExperience,
        double YearsAtCompany, char unemployedStatus, int reportedRent, double expectedTaxContribution, double UtilitiesCost, int GroceryCost){
            this->country = country;
            this->Industry = Industry;
            this->JobTitle = JobTitle; 

            this->YearlyPay = YearlyPay;
            this->WeeklyHours = WeeklyHours;
            this->HourlyWage = HourlyWage;
            this->YearsExperience = YearsExperience;
            this->YearsAtCompany = YearsAtCompany;
            this->unemployedStatus = unemployedStatus;
            this->reportedRent = reportedRent;
            this->expectedTaxContribution = expectedTaxContribution;
            this->UtilitiesCost = UtilitiesCost;
            this->GroceryCost = GroceryCost;
        }

std::string Person::printInformation(){
    std::ostringstream output;

    output << this->country << " " << this->YearlyPay << " " << this->WeeklyHours << " " << this->HourlyWage << " "
           << this->YearsExperience << " " << this->unemployedStatus << " " << this->reportedRent << " " << this->expectedTaxContribution
           << " " << this->GroceryCost << std::endl; 


    return output.str();
}