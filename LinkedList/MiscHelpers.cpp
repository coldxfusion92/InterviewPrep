/*
*   LinkedListHelpers.cpp
*/

// Headers.
#include "MiscHelpers.h"

vector<int> buildVectorOfElements()
{
    vector<int> elements;
    int inputInt = 0;

    cout << "Building list. Enter values; (-1) to finish" << endl;
    while (inputInt != -1)
    {
        cout << "Enter value: ";
        cin >> inputInt;

        if (inputInt == -1)
            break;

        elements.push_back(inputInt);
    }

	return elements;
}