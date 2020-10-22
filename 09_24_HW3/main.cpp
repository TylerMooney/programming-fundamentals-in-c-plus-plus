/*
Author: Tyler Mooney
Date: September 24th, 2019
Professor: Khiem Le
Compiler: GNU GCC

Purpose: Calculate the gross and net profit for a night at a move theater.

Notes: User will input Movie Name, Number of tickets sold (Child or Adult), & theater location.
Adult tickets are $10.75 each, Children tickets are $6.35 each
Theater keeps 20% of gross profit
Display gross profit, net profit, and amount paid to distributer with at most 2 decimal places
*/
#include <iostream>
#include<iomanip>

using namespace std;

int main()
{
    //variable initializations
    const double PERCENT_KEPT = 0.2;
    const double ADULT_PRICE = 10.75;
    const double CHILD_PRICE = 6.35;
    double profitGross, profitNet, profitDist;
    int ticketsChild, ticketsAdult;
    string movieTitle, locationTheater;

    //Statements prompt user to enter all required basic information
    cout << "Please enter the movie title: ";
    getline(cin, movieTitle);
    cout << "Movie title is " << movieTitle << endl;

    cout << "Please enter the number of adult tickets sold: ";
    cin >> ticketsAdult;
    cout << "Number of adult tickets sold is " << ticketsAdult << endl;

    cout << "Please enter the number of child tickets sold: ";
    cin >> ticketsChild;
    cout << "Number of child tickets sold is " << ticketsChild << endl;

    cout << "Please enter the theater's location: ";
    cin.ignore();
    getline(cin, locationTheater);
    cout << "Theater location is " << locationTheater << endl;

    //calculations for gross profit, net profit, and amount paid to distributors
    profitGross = (ticketsAdult * ADULT_PRICE) + (ticketsChild * CHILD_PRICE);
    profitNet = profitGross * PERCENT_KEPT;
    profitDist = profitGross - profitNet;

    //printing profit calculations and setprecision
    cout << "Gross profit is $" << setprecision(2) << fixed << profitGross << endl;
    cout << "Net profit is $" << setprecision(2) << profitNet << endl;
    cout << "Distributor profit is $" << setprecision(2) << profitDist << endl << endl; //extra endl for revenue report

    //printing revenue report containing all previous info in an organized layout
    cout << "Revenue Report" << endl;
    cout << "==============" << endl;
    cout << setw(28) << left << "Movie Name:" << right << setw(0) << movieTitle << endl;
    cout << setw(28) << left << "Theater Location:" << right << setw(0) << locationTheater << endl;
    cout << setw(28) << left << "Adult Tickets Sold:" << right << setw(9) << ticketsAdult << endl; //is set(9) due to it needing to be pushed 1 more to the right to line up
    cout << setw(28) << left << "Child Tickets Sold:" << right << setw(9) << ticketsChild << endl; //is set(9) due to it needing to be pushed 1 more to the right to line up
    cout << setw(28) << left << "Gross Box Office Profit:" << setw(0) << '$' << right << setw(8) << profitGross << endl;
    cout << setw(28) << left << "Net Box Office Profit:" << setw(0) << '$' << right << setw(8) << profitNet << endl;
    cout << setw(28) << left << "Amount Paid to Distributor:" << setw(0) << '$' << right << setw(8) << profitDist << endl;

    return 0;
}
