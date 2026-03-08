/*
*   LinkedListSolutions.cpp
*/

// Headers to indicate what class of problems can be played.
#include "LinkedListSolutions.h"
#include "TreeSolutions.h"

#define MIN_PROBLEM_NUM 1
#define MAX_PROBLEM_NUM 9

int main()
{
	// Variable to specify which problem to run.
	int c = 0;

    cout << "Play problem roulette - specify any number to run a unique problem, if invalid number specified, program ends." << endl;
    cout << "Enter a number to specify which problem to run (" << MIN_PROBLEM_NUM << " - " << MAX_PROBLEM_NUM << "): ";
    cin >> c;

    if (c < MIN_PROBLEM_NUM || c > MAX_PROBLEM_NUM)
    {
        cout << "Invalid problem number specified. The game ends before it can even begin..." << endl;
        return 0;
	}

    while (c >= MIN_PROBLEM_NUM && c <= MAX_PROBLEM_NUM)
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
        case 6:
            mergeKSortedLists();
			break;
        case 7:
            traversalType();
            break;
        case 8:
            levelOrderTraversal();
            break;
        case 9:
            isBinaryTreeBalanced();
            break;
        }

        cout << "Roll again: ";
        cin >> c;
    }

	cout << "Invalid number caught. Thanks for playing problem roulette! Program terminated." << endl;

    return 1;
}