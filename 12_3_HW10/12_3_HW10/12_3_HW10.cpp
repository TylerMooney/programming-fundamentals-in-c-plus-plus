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
int populateArrays(string fileName, int netIDArray[], string majorArray[], double gpaArray[], int arrSize, int & numRecords);
void displayAll(int netIDArray[], string majorArray[], double gpaArray[], int numRecords);
void displayLow(int netIDArray[], string majorArray[], double gpaArray[], int numRecords);
void displayHigh(int netIDArray[], string majorArray[], double gpaArray[], int numRecords);
void studentSearch(int netIDArray[], string majorArray[], double gpaArray[], int numRecords);

int main()
{
	//variable initialization
	int check, arrSize = 15, numRecords;
	string fileName;

	//array initialization
	string majorArray[15];
	int netIDArray[15];
	double gpaArray[15];

	//prompt user for file name
	cout << "Enter file name: ";
	cin >> fileName;

	check = populateArrays(fileName, netIDArray, majorArray, gpaArray, arrSize, numRecords);

	//If the function fails to open the file
	if (check == 1)
	{
		cout << "Error opening file" << endl;
		exit(EXIT_FAILURE);
	}

	//Displaying all information
	displayAll(netIDArray, majorArray, gpaArray, numRecords);
	displayLow(netIDArray, majorArray, gpaArray, numRecords);
	displayHigh(netIDArray, majorArray, gpaArray, numRecords);
	studentSearch(netIDArray, majorArray, gpaArray, numRecords);

	exit(EXIT_SUCCESS);
}

//Acquires information from the file and puts the
//information into the correct arrays.
int populateArrays(string fileName, int netIDArray[], string majorArray[], double gpaArray[], int arrSize, int& numRecords)
{
	//file for input
	ifstream inFile;
	inFile.open(fileName);

	//Opens file fills in info from file into arrays
	//if open fails, function returns 1
	if (inFile.fail())
		return 1;
	else
	{
		//initializing a counter
		int i = 0;

		//putting in the info from file into arrays, while making sure to not put in
		while (i < arrSize && inFile >> netIDArray[i] && inFile >> majorArray[i] && inFile >> gpaArray[i])
			i++;

		//sets record number to equal the correct number
		if (i != arrSize)
			numRecords = i;
		else
			numRecords = arrSize;
	}

	inFile.close();
	return 0;
}

//displays all information inside of the arrays
void displayAll(int netIDArray[], string majorArray[], double gpaArray[], int numRecords)
{
	//Printing number of records and header
	cout << "Number of records = " << numRecords << endl << endl;
	cout << "******\nPart 1\n******\n";

	//Printing NetID array info
	cout << "NetID array\n-----------\n";
	for(int i = 0; i < numRecords;)
	{
		cout << "netIDArray[" << i << "] = " << netIDArray[i];

		//Printing a comma when needed
		if ((i % 3) != 2 && i != (numRecords -1))
			cout << ", ";

		i++;

		//Prints a new line if three entries have been printed
		if ((i % 3) == 0)
			cout << endl;
	}

	//Printing Major array info
	cout << "\n\nMajor array\n-----------\n";
	for (int i = 0; i < numRecords;)
	{
		cout << "majorArray[" << i << "] = " << majorArray[i];

		//Printing a comma when needed
		if ((i % 3) != 2 && i != (numRecords - 1))
			cout << ", ";

		i++;

		//Prints a new line if three entries have been printed
		if ((i % 3) == 0)
			cout << endl;
	}

	//Printing GPA array info
	cout << "\n\nGPA array\n---------\n";
	for (int i = 0; i < numRecords;)
	{
		cout << "gpaArray[" << i << "] = " << gpaArray[i];

		//Printing a comma when needed
		if ((i % 3) != 2 && i != (numRecords - 1))
			cout << ", ";

		i++;

		//Prints a new line if three entries have been printed
		if ((i % 3) == 0)
			cout << endl;
	}

}

//displays the student with the lowest GPA
void displayLow(int netIDArray[], string majorArray[], double gpaArray[], int numRecords)
{
	//variable initialization
	int spot = 0;

	//finding student with lowest GPA
	for (int i = 0; i < numRecords; i++)
		if (gpaArray[i] < gpaArray[spot])
			spot = i;

	//Printing out info
	cout << "\n\nLowest GPA\n----------\nNetID is " << netIDArray[spot] << ", major is "
		 << majorArray[spot] << ", GPA = " << gpaArray[spot];
}

//displays the student with the highest GPA
void displayHigh(int netIDArray[], string majorArray[], double gpaArray[], int numRecords)
{
	//variable initialization
	int spot = 0;

	//finding student with highest GPA
	for (int i = 0; i < numRecords; i++)
		if (gpaArray[i] > gpaArray[spot])
			spot = i;

	//Printing out info
	cout << "\n\nHighest GPA\n-----------\nNetID is " << netIDArray[spot] << ", major is "
		<< majorArray[spot] << ", GPA = " << gpaArray[spot];
}

//Searches for student with matching netID
//and then displays their info
void studentSearch(int netIDArray[], string majorArray[], double gpaArray[], int numRecords)
{
	//variable initialization
	int counter = 0;
	int netID = 0, spot = 0;

	//printing header and looping search for student(s)
	cout << "\n\nSearch on student's netID\n-------------------------";

	//Prompt user for netID and searches for student info, until -1 is inputted
	while (netID != -1)
	{
		cout << "\nInput student's netID, -1 to quit: ";
		cin >> netID;
		while(counter < numRecords)
		{
			if (netID == netIDArray[counter])
			{
				spot = counter;
				counter = numRecords;
			}
			counter++;
		}
		counter = 0;

		//Prints out information if a netID was found, else it prints out no info was found
		if (netID == netIDArray[spot])
			cout << "NetID is " << netIDArray[spot] << ", major is " << majorArray[spot] << ", GPA = " << gpaArray[spot] << endl;
		else
			cout << "NetID not found\n";
	}
	
}
