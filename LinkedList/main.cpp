/*
*   LinkedListSolutions.cpp
*/

// Headers to indicate what class of problems can be played.
#include "LinkedListSolutions.h"

#define MIN_PROBLEM_NUM 1
#define MAX_PROBLEM_NUM 5

int main()
{
	// Variable to specify which problem to run.
	int c = 0;

    cout << "Play problem roulette - specify any number to run a unique problem, if invalid number specified, program ends." << endl;
    cout << "Enter a number to specify which problem to run (1-5): ";
    cin >> c;

    if (c < MIN_PROBLEM_NUM || c > MAX_PROBLEM_NUM)
    {
        cout << "Invalid problem number specified. The game ends before it can even begin..." << endl;
        return 0;
	}

    while (c >= 1 && c <= 5)
    {
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
        }

        cout << "Roll again: ";
        cin >> c;
    }

	cout << "Invalid number caught. Thanks for playing problem roulette! Program terminated." << endl;

    return 1;
}