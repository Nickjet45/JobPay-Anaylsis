#include "Country.hpp"


//Constructors does the same thing as State constructors
//Same assumptions made
Country::Country(){
    this->name = "";
    this->MeanGroceryCost = 0;
    this->MeanYearlySalary = 0;
    this->PercentUnemployed = 0;
    this->MeanTaxContribution = 0;
    this->MeanWeeklyHours = 0;
    this->MeanReportedRent = 0;
    isUS = false;
}

Country::Country(std::string name){
    this->name = name;
    this->MeanGroceryCost = 0;
    this->MeanYearlySalary = 0;
    this->PercentUnemployed = 0;
    this->MeanTaxContribution = 0;
    this->MeanWeeklyHours = 0;
    this->MeanReportedRent = 0;

    if(this->name == "United States of America")
        this->isUS = true;
    else
        this->isUS = false;
}

//Adds a citizen to the country
void Country::AddCitizen(Person citizen){
    //If the country is the U.S add the citizen to their respective state
    //Else add the citizen to the country itself
    if(isUS){
        citizens.push_back(citizen);
        //Find the state index
        if(stateIndex.count(citizen.GetState()) > 0){
            states.at(stateIndex[citizen.GetState()]).AddCitizen(citizen);
        }
        else{
            //Make a new state with that name and add it to the states vector
            State newState(citizen.GetState());
            stateIndex[newState.GetName()] = states.size();
            states.push_back(newState);

            //Citizen needs to be added to the last state
            states.at(states.size()-1).AddCitizen(citizen);
        }
    }
}

/**
 * For U.S (sum of all state means / number of states) will give the mean
 * For other countries (sum of all citizens / num citizens) will give it
 * 
 */

double Country::GetMeanSalary(){
    if(this->isUS){
        int mean = 0;
        for(size_t i= 0; i<states.size();i++)
            mean += states.at(i).GetMeanSalary();
        
        return (mean/states.size());
    }
    else
        return Stats::CalculateMean(citizens,1);
}

double Country::GetMeanHours(){
    if(this->isUS){
        int mean = 0;
        for(size_t i= 0; i<states.size();i++)
            mean += states.at(i).GetMeanSalary();
        
        return (mean/states.size());
    }
    else
        return Stats::CalculateMean(citizens,2);

}

double Country::GetMeanRent(){
    if(this->isUS){
        int mean = 0;
        for(size_t i= 0; i<states.size();i++)
            mean += states.at(i).GetMeanRent();
        
        return (mean/states.size());
    }
    else
        return Stats::CalculateMean(citizens,3);
}

double Country::GetMeanGrocery(){
    if(this->isUS){
        int mean = 0;
        for(size_t i= 0; i<states.size();i++)
            mean += states.at(i).GetMeanGrocery();
        
        return (mean/states.size());
    }
    else
        return Stats::CalculateMean(citizens,4);
}

double Country::GetMeanTax(){
    if(this->isUS){
        int mean = 0;
        for(size_t i= 0; i<states.size();i++)
            mean += states.at(i).GetMeanTax();
        
        return (mean/states.size());
    }
    else
        return Stats::CalculateMean(citizens,5);
}

double Country::GetUnemployed(){
    if(this->isUS){
        int mean = 0;
        for(size_t i= 0; i<states.size();i++)
            mean += states.at(i).GetUnemployed();
        
        return (mean/states.size());
    }
    else
        return Stats::CalculateMean(citizens,6);
}

std::string Country::printInformation(){
    std::ostringstream output;

    //if it's the U.S just output all of the state's information
    output << this->GetName() << ": \n";
    if(this->isUS)
        for(size_t i =0; i < this->states.size(); i++)
            output << states.at(i).GetName() << ": \n" <<states.at(i).printInformation() << std::endl;
    //Else output every citizen's information
    else
        for(size_t i =0; i < this->citizens.size(); i++)
            output << citizens.at(i).printInformation();


    return output.str();
}