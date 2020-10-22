/*
Author: Tyler Mooney
Date: December 2nd, 2019
Professor: Khiem Le
Compiler: GNU GCC

Purpose: Prompt user for file name, then
access students' records to display their netIDs, GPAs,
and majors. Then display the information of the students
with the lowest and highest GPA. Then give the user the
ability to search for any specific student's
information within the file.

Notes:
Functions:
    main(): main function
    populateArrays(): Places information into correct arrays.
    displayAll(): displays all information
    displayLow(): displays student info with lowest GPA
    displayHigh(): displays student info with highest GPA
    studentSearch(): prompt user for a student netID.
    Proceed to search for student with same netID and
    display their info, or "NetID not found"
    continue looping until user enters -1.

PopulateArrays Parameters:
Have each array based on a certain aspect of info:
    netIDArray: contains students' netIDs
    majorArray: contains students' majors
    gpaArray: contains students' GPAs
Array sizes are 15, ignore records past size.
If the number of records exceeds the array size,
assign the reference variable as the array size.
If the file open fails have the function return a 1,
if the file opens properly return 0.
*/

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

//function prototypes
int populateArrays(string fileName, string netIDArray[], string majorArray[], double gpaArray[], int arrSize, int & numRecords);
void displayAll();
void displayLow();
void displayHigh();
void studentSearch();

int main()
{
    //variable initialization
    int check, arrSize = 15, numRecords;
    string fileName;

    //array initialization
    string netIDArray[15], majorArray[15];
    double gpaArray[15];

    //prompt user for file name
    cout << "Enter file name: ";
    cin >> fileName;

    check = populateArrays(fileName, netIDArray, majorArray, gpaArray, arrSize, numRecords);

    //If the function fails to open the file
    if(check == 1)
    {
        cout << "Error opening file" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Number of records = " << numRecords;


    exit(EXIT_SUCCESS);
}

//Acquires information from the file and puts the
//information into the correct arrays.
int populateArrays(string fileName, string netIDArray[], string majorArray[], double gpaArray[], int arrSize, int & numRecords)
{
    //file for input
    ifstream inFile;
    inFile.open(fileName);

    //Opens file fills in info from file into arrays
    //if open fails, function returns 1
    if(inFile.fail())
        return 1;
    else
    {
        int i = 0;

        while(i < arrSize && inFile >> netIDArray[i] && inFile >> majorArray[i] && inFile >> gpaArray[i])
            i++;

        if(i != arrSize)
            numRecords = i;
        else
            numRecords = arrSize;
    }

    inFile.close();
    return 0;
}

//displays all information inside of the arrays
void displayAll()
{

}

//displays the student with the lowest GPA
void displayLow()
{

}

//displays the student with the highest GPA
void displayHigh()
{

}

//Searches for student with matching netID
//and then displays their info
void studentSearch()
{

}
