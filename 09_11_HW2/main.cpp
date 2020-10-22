/*
Author: Tyler Mooney
Date: September 11th, 2019
Professor: Khiem Le
Compiler: GNU GCC

Purpose: Prompt the user to enter various inputs, then have those inputs printed out.
The inputs for test scores 1, 2, & 3 will have their average taken and printed.

Notes: Make sure to use a variable to calculate the test average
*/
#include <iostream>

using namespace std;

int main()
{
    //variable initializations
    string firstName, lastName;
    double test1, test2, test3, testAverage;

    //First name Input/Output
    cout << "Please enter the student's first name: ";
    cin >> firstName;
    cout << "First name entered is " << firstName << endl;

    //Last name Input/Output
    cout << "Please enter the student's last name: ";
    cin >> lastName;
    cout << "Last name entered is " << lastName << endl;

    //Test scores Inputs/Outputs
    cout << "Please enter the student's test 1 score: ";
    cin >> test1;
    cout << "Test 1 score entered is " << test1 << endl;

    cout << "Please enter the student's test 2 score: ";
    cin >> test2;
    cout << "Test 2 score entered is " << test2 << endl;

    cout << "Please enter the student's test 3 score: ";
    cin >> test3;
    cout << "Test 3 score entered is " << test3 << endl;

    //Test average calculation & output
    testAverage = ((test1 + test2 + test3) / 300) * 100;
    cout << "The test average of " << firstName << ' ' << lastName << " is " << testAverage << endl;

    return 0;
}
