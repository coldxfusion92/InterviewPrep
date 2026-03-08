#pragma once

/*
*   LinkedListHelpers.h
*/

// Headers.
#include "LinkedListHelpers.h"
#include "MiscHelpers.h"

// Problem 1: Swap every 2 nodes in a doubly linked list.
// One helper f'n to do the swap of 2 nodes (not exported), and one main f'n to build the list and call the helper.
void swapEveryTwoNodesInDoublyLinkedList();		// Main
// Node* swapEveryTwoNodesHelper();				// Helper

// Problem 2: Swap Kth nodes in a singly linked list with n-Kth node (essentially reversing in-place).
void swapKthNodes();

// Problem 3: Interlace two singly linked lists.
void interlaceTwoSinglyLinkedLists();

// Problem 4: Reverse an integer represented as a linked list in place.
// Can also be used as a helper f'n for problem 5 - pass in an integer-as-alist as param to trigger that usage.
void reverseIntegerAsListInPlace(Node* subProblemList);

// Problem 5: Add two numbers represented by linked lists.
// One helper f'n to construct a list from the sum (not exported).
void addTwoIntegersAsLists();					// Main
// Node* sumOfLists(int sum);					// Helper

// Problem 6: Merge K sorted linked lists into one sorted linked list.
void mergeKSortedLists();