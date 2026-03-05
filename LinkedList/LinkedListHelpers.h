#pragma once

/*
*   LinkedListHelpers.h
*/

// Headers.
#include <iostream>
#include <vector>

// Namespaces.
using namespace std;

// Structure for a node in a doubly-capable linked list.
struct Node
{
	// Data and links.
    int data = 0;
    Node* prev = nullptr;
    Node* next = nullptr;

    // Optional flag to specify if being used as doubly linked list or not; default singly-linked.
	bool isDoublyLinkedList = false;

    // Node constructor.
    Node(int iData)
    {
        data = iData;
        prev = nullptr;
        next = nullptr;
    }
};

// F'n for creating a new singly linked list with 'numNodes' number of elements as provided in vector.
Node* createSinglyLinkedList(vector<int> elements);

// F'n for creating a new doubly list with 'numNodes' number of elements as provided in vector.
Node* createDoublyLinkedList(vector<int> elements);

// Helper f'n to print a list.
void printList(Node* list);

// Helper f'n to print doubly linked list in reverse (tests doubly linked list validity).
void printDoublyLinkedListInReverse(Node* list);