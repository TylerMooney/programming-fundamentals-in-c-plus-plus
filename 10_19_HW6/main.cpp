/*
Author: Tyler Mooney
Date: October 19th, 2019
Professor: Khiem Le
Compiler: GNU GCC

Purpose: Prompt the user to enter traffic accident statistics
for north, south, east, and west regions. Then a menu will be
displayed to display the safest region, least safe region, or
display all regions.

Notes:
Menu inputs:
    1. Safest region (display region with least accidents)
    2. least safe region (display region with most accidents)
    3. display all regions
Assume no two regions have the same accident total
Functions:
    getChoice(): prints menu, reads user input and determines if valid
    getAccidentTotal(): Acquires input, confirms input, and returns input into designated variable
    findSafest(): Determines region with least accidents and prints results
    findLeastSafe(): Determines region with most accidents and prints results
    displayAll(): Print all information for each region
*/


#include <iostream>

using namespace std;

//Function prototypes
int getAccidentTotal(string region);
int getChoice();
void findSafest(int totalNorth, int totalSouth, int totalEast, int totalWest);
void findLeastSafe(int totalNorth, int totalSouth, int totalEast, int totalWest);
void displayAll(int totalNorth, int totalSouth, int totalEast, int totalWest);

//Main function
int main()
{
    //Variable initialization
    int totalNorth, totalSouth, totalEast, totalWest, choice;

    //Acquiring values for each variable
    totalNorth = getAccidentTotal("north");
    totalSouth = getAccidentTotal("south");
    totalEast = getAccidentTotal("east");
    totalWest = getAccidentTotal("west");

    //Acquiring user choice and calling proper function
    choice = getChoice();
    if(choice == 1)
    {
        findSafest(totalNorth, totalSouth, totalEast, totalWest);
    }
    else if(choice == 2)
    {
        findLeastSafe(totalNorth, totalSouth, totalEast, totalWest);
    }
    else if (choice == 3)
    {
        displayAll(totalNorth, totalSouth, totalEast, totalWest);
    }
    else
    {
        cout << "Invalid choice\n";
    }

    cout << "Exiting\n";

    return 0;
}

//Prompts user to input accident total for said region, returns input
int getAccidentTotal(string region)
{
    int numAccident;

    cout << "Enter the accident total for the " << region << " region: ";
    cin >> numAccident;
    cout << "Accident total entered for " << region << " region is " << numAccident << endl;

    return numAccident;
}


//Displays menu, then prompt user for input. Return input if valid, if input is invalid return -1
int getChoice()
{
    int input;

    cout << "Menu\n";
    cout << "----\n";
    cout << "1->Display safest region, 2->Display least safe region, 3->Display all\n";
    cin >> input;
    cout << "You entered " << input << endl;

    //Checks to see if input is valid
    if(input == 1 || input == 2 || input == 3)
    {
        return input;
    }
    else
    {
        return -1;
    }
}

//Determines which region has the least amount of accidents and then prints results
void findSafest(int totalNorth, int totalSouth, int totalEast, int totalWest)
{
    int lowest = totalNorth;
    string region = "north";

    if(totalSouth < lowest)
    {
        lowest = totalSouth;
        region = "south";
    }
    if(totalWest < lowest)
    {
        lowest = totalWest;
        region = "west";
    }
    if(totalEast < lowest)
    {
        lowest = totalEast;
        region = "east";
    }

    cout << "Region " << region << " is the safest, with " << lowest << " accidents\n";
}


//Determines which region has the most accidents and then prints results
void findLeastSafe(int totalNorth, int totalSouth, int totalEast, int totalWest)
{
    int highest = totalNorth;
    string region = "north";

    if(totalSouth > highest)
    {
        highest = totalSouth;
        region = "south";
    }
    if(totalWest > highest)
    {
        highest = totalWest;
        region = "west";
    }
    if(totalEast > highest)
    {
        highest = totalEast;
        region = "east";
    }

    cout << "Region " << region << " is the least safe, with " << highest << " accidents\n";
}

//Displays all information acquired on each region
void displayAll(int totalNorth, int totalSouth, int totalEast, int totalWest)
{
    cout << "North region has " << totalNorth << " accidents\n";
    cout << "South region has " << totalSouth << " accidents\n";
    cout << "East region has " << totalEast << " accidents\n";
    cout << "West region has " << totalWest << " accidents\n";
}
