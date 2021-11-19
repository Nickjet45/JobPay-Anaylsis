#include "Person.hpp"

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