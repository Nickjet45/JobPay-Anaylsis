#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>
#include <sstream>

class Person{
    private:
        std::string country;
        std::string state;     
        int YearlyPay;
        double WeeklyHours;
        double HourlyWage;
        double YearsExperience;
        char unemployedStatus;
        int reportedRent;
        int expectedTaxContribution;
        int GroceryCost;
    public:
        explicit Person();
        explicit Person(std::string country, int YearlyPay, int WeeklyHours, double HourlyWage, double YearsExperience,
        char unemployedStatus, int reportedRent, int expectedTaxContribution, int GroceryCost);

        std::string GetCountry() const {return this->country;};
        void SetCountry(std::string country) {this->country = country;}

        std::string GetState() const {return this->state;};
        void GetState(std::string state) {this->state = state;}

        int GetYearlyPay() const {return this->YearlyPay;}
        void SetYearlyPay(int YearlyPay) {this->YearlyPay = YearlyPay;}

        double GetWeeklyHours()const{return this->WeeklyHours;}
        void SetWeeklyHours(double WeeklyHours){this->WeeklyHours = WeeklyHours;} 

        double GetYearsExperience() const{return this->YearsExperience;}
        void SetYearsExperience(double YearsExperience){this->YearsExperience = YearsExperience;}

        char GetUnemployedStatus()const {return this->unemployedStatus;}
        void SetUnemployedStatus(char unemployment){this->unemployedStatus = unemployment;}

        int GetReportedRent()const {return this->reportedRent;}
        void SetReportedRent(int reportedRent) {this->reportedRent = reportedRent;}

        int GetExpectedTaxContribution()const{return this->expectedTaxContribution;}
        void SetExpectedTaxContribution(int expectedTaxContribution){this->expectedTaxContribution=expectedTaxContribution;}

        int GetGroceryCost()const {return this->GroceryCost;}
        void SetGroceryCost(int cost){this->GroceryCost = cost;}


        std::string printInformation();


};




#endif