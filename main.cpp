//Driver of anaylsis
#include <stdlib.h>
#include "./header/Country.hpp"
#include <iostream>
#include <fstream>

/**
 * The main driver for the statisitcal analysis of the data
 * Incorporates both a menu system and the ability to convert the csv into an excel sheet
 * 
 */

int menu(){
    std::cout << "What would you like to do? \n"
              << "1- List countries\n"
              << "2- Find mean values\n"
              << "3- Beautify csv into excel sheet\n"
              << "4- Exit Program\n"
              << "Enter choice: ";
    int answer;
    std::cin >> answer;

    return answer;
}

int submenu(){
    int answer;

    std::cout << "What would you like to find the mean values for? \n"
              << "1- Given industry\n"
              << "2- Country\n"
              << "3- State\n"
              << "4- Go back\n";

    std::cin >> answer;
    return answer;
}

//Imports the data and stores each country into the vector of countries
void importData(std::vector<Country> &countries, std::unordered_map<std::string, int> &map){

    //Open the file
    std::ifstream input;
    input.open("Data.csv");

    if(input.fail()){
        std::cout << "Failed to open Data.csv, check that it is in the same directory as main.cpp";
        exit(0);
    }

    //First line is useless Google Sheets stuff
    std::string line;
    std::getline(input, line);

    //Reset line
    line = "";

    //While there are still lines to be read in
    while(std::getline(input,line)){

        //All data needed
        std::string country;
        std::string state;
        std::string Industry;
        std::string JobTitle;     
        std::string YearlyPay;
        std::string WeeklyHours;
        std::string HourlyWage;
        std::string YearsExperience;
        std::string YearsAtCompany;
        std::string unemployedStatus;
        std::string reportedRent;
        std::string expectedTaxContribution;
        std::string UtilitiesCost;
        std::string GroceryCost;

        //Create a stream and delimit it using the comma
        std::istringstream process(line);

        //Data format is --> 
        //Row -> Time -> Country -> State -> Industry -> Title -> Yearly salary -> Weekly Hours -> Hourly Wage ->Years @ company
        // -> Years Experience -> Unemployed -> Average rent -> Tax -> Utilities -> Groceries
        std::string dummy; //Simply to store Row and time as it's unneeded
        std::getline(process,dummy, ',');
        std::getline(process,dummy, ',');

        //Now get the real data
        std::getline(process,country, ',');
        std::getline(process,state, ',');
        std::getline(process,Industry, ',');
        std::getline(process,JobTitle, ',');
        std::getline(process,YearlyPay, ',');
        std::getline(process,WeeklyHours, ',');
        std::getline(process,HourlyWage, ',');
        std::getline(process,YearsExperience, ',');
        std::getline(process,YearsAtCompany, ',');
        std::getline(process,unemployedStatus, ',');
        std::getline(process,reportedRent, ',');
        std::getline(process,expectedTaxContribution, ',');
        std::getline(process,UtilitiesCost, ',');
        std::getline(process,GroceryCost, ',');

        //Now to filter the data

        //U.S has too many abbreviations
        for(int i =0; i < country.size();i++){
            if(country[i] == '.' || country[i] == ' ')
                continue;
            country[i] = tolower(country[i]);
        }
        if(country == "united states of america"||country == "united states" ||country == "u.s.a" || country == "u.s")
            country = "United States of America";

        //Reuppercase first letter for other countries
        country[0] = toupper(country[0]);

        //Next I need to format the salary and hourly wages
        //If the first character of the salary is a character, remove it so that it can be converted to an integer
        if(YearlyPay == "N/A" || YearlyPay == ""){
            YearlyPay = "-1";
        }else{
            if(isalpha(YearlyPay[0]))
                YearlyPay.erase(0);
        }
        
        if(WeeklyHours == "N/A" || WeeklyHours == "")
            WeeklyHours = "-1";
        
        if(HourlyWage == "N/A")
            HourlyWage = "-1";
        else{
            if(isalpha(HourlyWage[0])){
                HourlyWage.erase(0);
            }
        }

        if(YearsAtCompany == "N/A")
            YearsAtCompany = "-1";
        
        if(unemployedStatus.size() > 1)
            unemployedStatus = unemployedStatus[0];
        
        if(reportedRent == "NA" || reportedRent == "Na" ||reportedRent == "N/A" || reportedRent == "Unsure" || reportedRent == "") //Java toUpper is so much better
            reportedRent = "-1";
        else if(isalpha(reportedRent[0]))
            reportedRent.erase(0);
        
        if(expectedTaxContribution == "Unsure" || expectedTaxContribution == "UNSURE" || expectedTaxContribution == "Unknown")
            expectedTaxContribution = "-1";
        else if(isalpha(expectedTaxContribution[0]))
            expectedTaxContribution.erase(0);

        if(UtilitiesCost == "NA" || UtilitiesCost == "N/A" || UtilitiesCost == "")
            UtilitiesCost = "-1";
        else{
            if(isalpha(UtilitiesCost[0]))
                UtilitiesCost.erase(0);
        }
        
        if(GroceryCost == "NA" || GroceryCost == "N/A" || GroceryCost == "")
            GroceryCost = "-1";
        else{
            if(isalpha(GroceryCost[0]))
                GroceryCost.erase(0);
        }

        //FINALLY MAKE THE PERSON
        Person citizen(country,state,Industry, JobTitle, std::stoi(YearlyPay), std::stoi(WeeklyHours),std::stod(HourlyWage),
        std::stod(YearsExperience), std::stod(YearsAtCompany), tolower(unemployedStatus[0]), std::stoi(reportedRent),
        std::stod(expectedTaxContribution),std::stod(UtilitiesCost), std::stoi(GroceryCost) );

        //Add the person to their proper country

        if(map.count(citizen.GetCountry()) > 0){
            countries.at(map[citizen.GetCountry()]).AddCitizen(citizen);
        }
        else{
            map[citizen.GetCountry()] = countries.size();
            Country country(citizen.GetCountry());
            countries.push_back(country);
            countries.at(countries.size()-1).AddCitizen(citizen);
        }
    }
}


int main(){

    //Pull the latest google sheets data
    system("Python pull.py");

    //Import the data
    std::vector<Country> countries;
    std::unordered_map<std::string, int> countryIndex;
    importData(countries, countryIndex);

    //While user has yet to exit the program
    while(true){
        //Call the super menu
        int choice = menu();

        //Based on that choice perform an action

        switch(choice){

            case 4:
                exit(0);
                break; //Useless tbh
            //Default redisplays menu
            default:
                std::cout << "Invalid choice, redisplaying menu.\n";
                break;
        }
    }



    return 0;
}