/*
*   LinkedListHelpers.cpp
*/

// Headers.
#include "LinkedListHelpers.h"

Node* createSinglyLinkedList(vector<int> elements)
{
    // Edge case: 0 list size is invalid.
    if (elements.size() <= 0)
    {
        cout << "Invalid number of nodes specified." << endl;
        return nullptr;
    }

    cout << "Creating singly linked list.....";

    // Head node and use tmp so that head can be returned.
    Node* head = new Node(elements[0]);
    Node* tmp = head;

    for (int i = 1; i < elements.size(); i++)
    {
        // Creating the list.
        tmp->next = new Node(elements[i]);
        tmp = tmp->next;
    }

	cout << "Done" << endl;

    return head;
}

Node* createDoublyLinkedList(vector<int> elements)
{
    // Edge case: 0 list size is invalid.
    if (elements.size() <= 0)
    {
        cout << "Invalid number of nodes specified." << endl;
        return nullptr;
    }

    cout << "Creating new doubly linked list.....";

    // Head node and use tmp so that head can be returned.
    Node* head = new Node(elements[0]);
    Node* tmp = head;

    // Create rest of the list.
    for (int i = 1; i < elements.size(); i++)
    {
        // Data.
        tmp->next = new Node(elements[i]);

        // Next and prev links.
        Node* prevNode = tmp;
        tmp = tmp->next;
        tmp->prev = prevNode;
    }

    cout << "Done" << endl;

    return head;
}

void printList(Node* list)
{
    // tmp Node to keep pass-by-reference list untouched
    Node* tmp = list;

    cout << "List is: ";

    // Iterate over list to print.
    while (tmp->next != nullptr)
    {
        cout << tmp->data << " <-> ";
        tmp = tmp->next;
    }
    cout << tmp->data;

    cout << " :End of list." << endl;
}

void printDoublyLinkedListInReverse(Node* list)
{
    // tmp Node to keep pass-by-reference list untouched
    Node* tmp = list;

    cout << "Reverse list is: ";

    // Iterate to the end of the list.
    while (tmp->next != nullptr)
        tmp = tmp->next;

    // Print list in reverse using prev links.
    while (tmp->prev != nullptr)
    {
        cout << tmp->data << " <-> ";
        tmp = tmp->prev;
    }
    cout << tmp->data;

    cout << " :End of list." << endl;
}