/*
Author: Tyler Mooney
Date: October 10th, 2019
Professor: Khiem Le
Compiler: GNU GCC

Purpose: Take two primary colors that the user chooses
and mix them to get a secondary color. If the user doesn't
properly input the correct numbers/colors display an error.

Notes: Use int constants for RED, BLUE, & YELLOW. purple, orange, and green are optional.
Color Combinations:
    Red + Blue = Purple
    Red + Yellow = Orange
    Blue + Yellow = Green
When comparing the combinations, use the constants.
End program with a new line.
*/

#include <iostream>

using namespace std;

int main()
{
    //variable initializations
    const int RED = 1, BLUE = 2, YELLOW = 3;
    int color1, color2;

    //Prompt user for inputs
    cout << "Enter your two primary colors: 1 for red, 2 for blue and 3 for yellow: ";
    cin >> color1;
    cin >> color2;

    //Printing results
    cout << "You entered " << color1 << ", " << color2 << endl;

    //Checking combinations with if/else ifs
    //The nested if/elses are to put the primary colors in the correct order of how they were inputted
    if((color1 == RED && color2 == BLUE) || (color1 == BLUE && color2 == RED))
    {
        if(color1 == RED)
            cout << "Primary colors are red and blue, resulting secondary color is purple" << endl;
        else
            cout << "Primary colors are blue and red, resulting secondary color is purple" << endl;
    }
    else if ((color1 == RED && color2 == YELLOW) || (color1 == YELLOW && color2 == RED))
    {
        if(color1 == RED)
            cout << "Primary colors are red and yellow, resulting secondary color is orange" << endl;
        else
            cout << "Primary colors are yellow and red, resulting secondary color is orange" << endl;
    }
    else if((color1 == BLUE && color2 == YELLOW) || (color1 == YELLOW && color2 == BLUE))
    {
        if(color1 == BLUE)
            cout << "Primary colors are blue and yellow, resulting secondary color is green" << endl;
        else
            cout << "Primary colors are yellow and blue, resulting secondary color is green" << endl;
    }
    else
    {
        cout << "Invalid colors" << endl;
    }

    return 0;
}
