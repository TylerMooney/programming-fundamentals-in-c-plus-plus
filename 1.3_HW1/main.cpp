/*
Author: Tyler Mooney
Date: September 5th, 2019
Professor: Khiem Le
Compiler: GNU GCC

Purpose: The purpose of the program is to create
triangles and rectangles using spaces, *s, and $s.

Notes/To-Dos:
Separate each shape with an extra endl at the end of each shape.
Triangles are 4 tall and should be 1 char wide (at the top) to 7 char wide (at the bottom)
Rectangles should be 3 tall and 2 wide
*/
#include <iostream>

using namespace std;

int main()
{
    char myDot = '*';
    char mySpace = ' ';

    //First Shape, Triangle
    cout << mySpace << mySpace << mySpace << myDot << endl;
    cout << mySpace << mySpace << myDot << myDot << myDot << endl;
    cout << mySpace << myDot << myDot << myDot << myDot << myDot << endl;
    cout << myDot << myDot << myDot << myDot << myDot << myDot << myDot << endl << endl;

    //Second Shape, Rectangle
    cout << myDot << myDot << endl;
    cout << myDot << myDot << endl;
    cout << myDot << myDot << endl << endl;

    myDot = '$';

    //Third Shape, Triangle
    cout << mySpace << mySpace << mySpace << myDot << endl;
    cout << mySpace << mySpace << myDot << myDot << myDot << endl;
    cout << mySpace << myDot << myDot << myDot << myDot << myDot << endl;
    cout << myDot << myDot << myDot << myDot << myDot << myDot << myDot << endl << endl;

    //Fourth & Final Shape, Rectangle
    cout << myDot << myDot << endl;
    cout << myDot << myDot << endl;
    cout << myDot << myDot << endl;

    return 0;
}
