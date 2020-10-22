/*
Author: Tyler Mooney
Date: October 10th, 2019
Professor: Khiem Le
Compiler: GNU GCC

Purpose: Prompt user to input the weight of a package and the distance it will travel,
then display the charges

Notes:
The shipping charge is displayed with up 2 two decimal places
Valid inputs:
    larger than 0kg and less than or equal to 20kg
    Distance is no less than 10 mi and no more than 3000 mi.
The rate is based off of every 500 miles
The miles is rounded up, i.e. 510 mi -> 1000 mi
Rates per 500 mi:
    2kg or less: $1.10
    over 2kg but no more than 6kg: $2.20
    over 6kg but no more than 10kg: $3.70
    over 10kg but no more than 20kg: $4.80
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //Variable initialization
    const double RATE2 = 1.1, RATE6 = 2.2, RATE10 = 3.7, RATE20 = 4.8;
    double weight;
    int roundedMultiple , distance;

    //Prompt user for input
    cout << "Enter the weight of the package in kilograms (max 20 Kg): ";
    cin >> weight;
    cout << "Weight entered is " << weight << endl;

    //checking for valid weight input
    if (weight < 0)
        cout << "Weight must be greater than zero." << endl;
    else if(weight > 20)
        cout << "We do not ship packages of more than 20 Kg." << endl;
    else
    {
        cout << "Enter the distance to be shipped: (min 10 Mi, max 3000 Mi): ";
        cin >> distance;
        cout << "Distance entered is " << distance << endl;

        //Checking for valid distance input and then doing calculations if conditional is passed
        if(distance < 10 || distance > 3000)
            cout << "We do not ship less than 10 miles or more than 3000 miles.";
        else
        {
            //Round distance, calculate total charge, and print result
            roundedMultiple = ((distance - 1) / 500) + 1;

            if (weight <= 2)
                cout << fixed << setprecision(2) << "The shipping charge is $" << roundedMultiple * RATE2;
            else if (weight > 2 && weight <= 6)
                cout << fixed << setprecision(2) << "The shipping charge is $" << roundedMultiple * RATE6;
            else if (weight > 6 && weight <= 10)
                cout << fixed << setprecision(2) << "The shipping charge is $" << roundedMultiple * RATE10;
            else
                cout << fixed << setprecision(2) << "The shipping charge is $" << roundedMultiple * RATE20;
        }
    }

    return 0;
}
