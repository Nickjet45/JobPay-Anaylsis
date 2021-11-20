#include "Stats.hpp"


//Mean code represents what type of mean is being taken (reduces functions needed)
double Stats::CalculateMean(std::vector<Person> data, int meanCode){
        double mean = 0;

        switch(meanCode){
            //Salary
            case 1:
                for(size_t i =0; i < data.size(); i++){
                    mean += data.at(i).GetYearlyPay();
                }
                break;
            //Hours worked
            case 2:
                 for(size_t i =0; i < data.size(); i++){
                    mean += data.at(i).GetWeeklyHours();
                }
                break;

            //Rent
            case 3:
            for(size_t i =0; i < data.size(); i++){
                    mean += data.at(i).GetReportedRent();
                }
                break;
            
            //Grocery
            case 4:
                 for(size_t i =0; i < data.size(); i++){
                    mean += data.at(i).GetGroceryCost();
                }
                break;
            
            //Tax contribution
            case 5:
                for(size_t i =0; i < data.size(); i++){
                    //Unknown data should be excluded
                    if(data.at(i).GetExpectedTaxContribution() != -1)
                        mean += data.at(i).GetExpectedTaxContribution();
                }
                break;

            //Percent unemployed
            case 6:
                for(size_t i =0; i < data.size(); i++){
                    if(tolower(data.at(i).GetUnemployedStatus()) == 'y')
                        mean += data.at(i).GetYearlyPay();
                }
                break;
            //Invalid code message
            default:
                return -1;
        }


        return (mean/data.size());
}
