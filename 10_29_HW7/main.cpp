/*
Author: Tyler Mooney
Date: Oct. 29th, 2019
Professor: Khiem Le
Compiler: GNU GCC

Purpose: Prompt user for the scores of five different judges,
then remove the highest score and the lowest score, then calculate
and display the remaining average among the three remaining scores

Notes:
A score cannot be lower than 0 or larger than 10, if this occurs
an error message will be displayed and the exit statement is executed
When calculating the average minus the highest and lowest score
in the equation in order to shorten code
Functions:
    getJudgeData: prompt user for a judge's score, and assign that to a variable.
    check each input to see if it's invalid. (repeat five times)
    calcScore: acquire the 5 scores, drop the highest and lowest score, then calculate
    the average of the remaining three scores and display said average
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

//function prototypes
void getJudgeData(double & val1, double & val2, double & val3, double & val4, double & val5);
void calcScore(double val1, double val2, double val3, double val4, double val5);

//Main function
int main()
{
    //variable initializations
    double val1, val2, val3, val4, val5;

    //calling other functions
    getJudgeData(val1, val2, val3, val4, val5);
    calcScore(val1, val2, val3, val4, val5);

    //Displaying exit message if program runs correctly
    //Exits with EXIT_SUCCESS b/c of program running correctly
    cout << "Normal termination, exiting\n";
    exit(EXIT_SUCCESS);
}

//prompt user for 5 different judges' scores and assign them to a variable
void getJudgeData(double & val1, double & val2, double & val3, double & val4, double & val5)
{
    //prompt user for judge's score, and then checking if input is valid
    cout << "Enter a judge's score: ";
    cin >> val1;
    if (val1 < 0 || val1 > 10)
    {
        cout << "The score must be between 0.0 and 10.0, exiting\n";
        exit(EXIT_FAILURE);
    }

    //prompt user for judge's score, and then checking if input is valid
    cout << "Enter a judge's score: ";
    cin >> val2;
    if (val2 < 0 || val2 > 10)
    {
        cout << "The score must be between 0.0 and 10.0, exiting\n";
        exit(EXIT_FAILURE);
    }

    //prompt user for judge's score, and then checking if input is valid
    cout << "Enter a judge's score: ";
    cin >> val3;
    if (val3 < 0 || val3 > 10)
    {
        cout << "The score must be between 0.0 and 10.0, exiting\n";
        exit(EXIT_FAILURE);
    }

    //prompt user for judge's score, and then checking if input is valid
    cout << "Enter a judge's score: ";
    cin >> val4;
    if (val4 < 0 || val4 > 10)
    {
        cout << "The score must be between 0.0 and 10.0, exiting\n";
        exit(EXIT_FAILURE);
    }

    //prompt user for judge's score, and then checking if input is valid
    cout << "Enter a judge's score: ";
    cin >> val5;
    if (val5 < 0 || val5 > 10)
    {
        cout << "The score must be between 0.0 and 10.0, exiting\n";
        exit(EXIT_FAILURE);
    }
}

//Drop the highest and lowest scores, then calculate and display
//the average of the three remaining scores
void calcScore(double val1, double val2, double val3, double val4, double val5)
{
    //Finding the lowest values out of the five
    double lowest = val1;
    if(val2 < lowest)
        lowest = val2;
    if(val3 < lowest)
        lowest = val3;
    if(val4 < lowest)
        lowest = val4;
    if(val5 < lowest)
        lowest = val5;

    //finding the highest value out of the five
    double highest = val1;
    if(val2 > highest)
        highest = val2;
    if(val3 > highest)
        highest = val3;
    if(val4 > highest)
        highest = val4;
    if(val5 > highest)
        highest = val5;

    //Displaying message and calculation of score average
    cout << "After dropping the lowest and highest scores, the average score was " << fixed
    << setprecision(1) << (val1 + val2 + val3 + val4 + val5 - highest - lowest) / 3 << ".\n";


}
