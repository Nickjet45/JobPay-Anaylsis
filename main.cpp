//Driver of anaylsis
#include <stdlib.h>
#include "./header/Country.hpp"
#include <iostream>

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
              << "4- Exit menu\n"
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

int main(){

    //Pull the latest google sheets data
    system("Python pull.py");

    //Import the data
    std::vector<Country> countries;

    //While user has yet to exit the program
    while(true){
        //Call the super menu
        int choice = menu();

        //Based on that choice perform an action

        switch(choice){


            //Default redisplays menu
            default:
                std::cout << "Invalid choice, redisplaying menu.\n";
                break;
        }
    }



    return 0;
}