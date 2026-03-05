/*
*   LinkedListSolutions.cpp
*/

// Headers to indicate what class of problems can be played.
#include "LinkedListSolutions.h"

// Namespaces.
using namespace std;

int main()
{
	// Variable to specify which problem to run.
	int c = 0;

    while (c <= 0)
    {
        // Play problem roulette - specify any number to run a unique problem, if invalid number specified, program ends.
        cout << "Enter a number to specify which problem to run (1-5); any other number quits the program: ";
		cin >> c;

        switch (c)
        {
        case 1:
            swapEveryTwoNodesInDoublyLinkedList();
            break;
        case 2:
            swapKthNodes();
            break;
        case 3:
            interlaceTwoSinglyLinkedLists();
            break;
        case 4:
            reverseIntegerAsListInPlace(nullptr);
            break;
        case 5:
            addTwoIntegersAsLists();
            break;
        default:
            cout << "Invalid problem number specified. Default quits the loop; cya!" << endl;
            break;
        }
    }

	cout << "Thanks for playing problem roulette! Program terminated." << endl;

    return 1;
}