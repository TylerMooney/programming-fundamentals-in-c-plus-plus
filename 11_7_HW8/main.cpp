/*
Author: Tyler Mooney
Date: November 7th, 2019
Professor: Khiem Le
Compiler: GNU GCC

Purpose: Prompt the user for the weight of a package
and the distance a package will travel, the calculate
and display the charges

Notes:
The shipping charge is displayed with up 2 two decimal places
The rate is based off of every 500 miles
The miles is rounded up, i.e. 510 mi -> 1000 mi
Exit failure prompt: "Too many invalid attempts, exiting\n"
Exit success prompt: "Exiting\n"
Valid inputs:
    larger than 0kg and less than or equal to 20kg
    Distance is no less than 10 mi and no more than 3000 mi.
Rates per 500 mi:
    2kg or less: $1.10
    over 2kg but no more than 6kg: $2.20
    over 6kg but no more than 10kg: $3.70
    over 10kg but no more than 20kg: $4.80
Functions:
    main(): Give user menu to select ship package or quit,
    then prompt user to select. If ship package is chosen,
    call the functions below then display charges. If quit
    is chosen, display exit success prompt and exit program.
    getWeight(): Use a while loop to ask for the weight.
    The user will have 5 attempts, if they're unable to
    input a valid input within these attempts, display an
    error message and exit the program.
    getDistance(): Use a while loop to ask for the distance.
    The user will have 5 attempts, if they're unable to
    input a valid input within these attempts, display an
    error message and exit the program.
    calculateCharges(): calculates the charges and returns
    it as a double
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//function prototypes
double getWeight();
int getDistance();
double calculateCharges(double weight, int distance);

int main()
{
    //variable initialization
    int input = 0, distance;
    double weight, charge;

    //Prompts user for input, and checks if input is valid
    while(input != 2)
    {
        cout << "1->Ship package, 2-> Quit: ";
        cin >> input;

        if(input == 1)
        {
            //Call all 3 functions to gather variables
            weight = getWeight();
            distance = getDistance();
            charge = calculateCharges(weight, distance);

            cout << fixed << setprecision(2) << "The shipping charge is $" << charge << endl << endl;
        }
    }

    cout << "Exiting\n";
    exit(EXIT_SUCCESS);
}

//Prompt user for the weight of the package up to 5 times.
//If user is unable to provide a valid input, exit program
double getWeight()
{
    int counter = 0;
    double weight;

    //prompt user for weight
    cout << "Enter the weight of the package in kilograms (max 20 Kg): ";
    cin >> weight;
    cout << fixed << setprecision(2) << "Weight entered is " << weight << endl;

    //Checks if input is valid up to 5 times
    while(counter != 5)
    {
        //Checking if input is valid
        if(weight >= 1 && weight <= 20)
            return weight;

        //failed attempt message, and counter increments by one
        cout << "Weight is invalid, must be between 0 and 20 kg, please reenter: ";
        cin >> weight;
        counter++;
    }

    //If all 5 attempts fail, exit failure prompt is displayed and occurs
    cout << "Too many invalid attempts, exiting\n";
    exit(EXIT_FAILURE);
}

//Prompt user for the distance the package will travel up to 5 times.
//If user is unable to provide a valid input, exit program
int getDistance()
{
    int counter = 0, distance;

    //prompt user for distance
    cout << "Enter the distance to be shipped: (min 10 Mi, max 3000 Mi): ";
    cin >> distance;
    cout << "Distance entered is " << distance << endl;

    //Checks if input is valid up to 5 times
    while(counter != 5)
    {
        //Checking if input is valid
        if(distance >= 10 && distance <= 3000)
            return distance;

        //failed attempt message, and counter increments by one
        cout << "Distance must be between 10 and 3000 miles, please reenter: ";
        cin >> distance;
        counter++;
    }

    //If all 5 attempts fail, exit failure prompt is displayed and occurs
    cout << "Too many invalid attempts, exiting\n";
    exit(EXIT_FAILURE);
}

//Calculates and returns the shipping charge
double calculateCharges(double weight, int distance)
{
    //variable initialization
    const double RATE2 = 1.1, RATE6 = 2.2, RATE10 = 3.7, RATE20 = 4.8;
    int roundedMultiple;

    //Round distance, calculate total charge, and print result
    roundedMultiple = ((distance - 1) / 500) + 1;

    if (weight <= 2)
        return roundedMultiple * RATE2;
    else if (weight > 2 && weight <= 6)
        return roundedMultiple * RATE6;
    else if (weight > 6 && weight <= 10)
        return roundedMultiple * RATE10;
    else
        return roundedMultiple * RATE20;

}
