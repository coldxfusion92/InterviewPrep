/*
*   LinkedListSolutions.cpp
*/

// Headers.
#include "LinkedListSolutions.h"

// Namespaces.
using namespace std;

// ******************************************************* 1 *******************************************************
Node* swapEveryTwoNodesHelper(Node* dList)
{
    // 6 links to change:
    // 1. node1's prev's next to node2.
    // 2. node1's prev to node2.
    // 3. node1's next to node2's next.
    // 4. node2's next's prev to node1.
    // 5. node2's next to node1.
    // 6. node2's prev to node1's prev.

    // Create new empty node to keep track of beginning of list post-swap.
    Node* node0 = new Node(0);
    node0->next = dList;
    
    // Assign Node1, but also assign its prev to Node0.
    Node* node1 = dList;
    node1->prev = node0;

    // Node2 to keep track of node to swap Node1 with.
    Node* node2;

    while (node1 != nullptr)
    {
        // Point node2 at second node.
        node2 = node1->next;

        // In the case of odd number of nodes, node2 will at some point be nullptr - no more swaps to be done.
        if (node2 == nullptr)
            break;

        // Store node1's prev's for its next, and node2's next for its prev.
        Node* tmp1 = node1->prev;
        Node* tmp2 = node2->next;

        // Swap links for the 2 elements in question - 4/6 links.
        node1->next = node2->next;
        node2->prev = node1->prev;
        node1->prev = node2;
        node2->next = node1;

        // Clean up links on either side - 2/6 links.
        if (tmp1)
            tmp1->next = node2;
        if (tmp2)
            tmp2->prev = node1;

        // Iterate node1 for the next swap.
        node1 = node1->next;
    }

    return node0->next;
}

void swapEveryTwoNodesInDoublyLinkedList()
{
    cout << "Problem: Swapping every 2 elements in a doubly linked list." << endl;

    // Build vector of elements from user input.
    vector<int> elements = buildVectorOfElements();

    // Construct doubly linked list from the built vector.
    Node* dList = createDoublyLinkedList(elements);
    if (dList == nullptr)
    {
        cout << "Uh oh....list creation failed." << endl;
        return;
    }

    // Print the list forwards and backwards (for kicks).
	cout << "Printing input list forwards and backwards before swap:" << endl;
    printList(dList);
    printDoublyLinkedListInReverse(dList);

    // Implement swap algorithm and print list to see the success story (can't believe I didn't get this).
    dList = swapEveryTwoNodesHelper(dList);

	// Print the list after swap.
	cout << "Printing output list after swap:" << endl;
    printList(dList);

    return;
}


// ******************************************************* 2 *******************************************************
void swapKthNodes()
{
    cout << "Problem: Swapping every Kth node in a singly linked list with n-Kth node." << endl;

    // Build vector of elements from user input.
    vector<int> elements = buildVectorOfElements();

    // Construct singly linked list from the built vector.
    Node* sList = createSinglyLinkedList(elements);
    if (sList == nullptr)
    {
        cout << "Uh oh....list creation failed." << endl;
        return;
    }

	// Print the input list.
	cout << "Input list is:" << endl;
	printList(sList);

    // Two nodes to swap.
    Node* first = sList;
    Node* last = sList;

    // Traverse to n/2 of list.
    for (int i = 0; i < elements.size() / 2; i++)
    {
        // Traverse to N-Kth node.
        for (int j = 0; j < (elements.size() - 1) - i; j++)
        {
            last = last->next;
        }

        // Swap the data.
        int tmp = first->data;
        first->data = last->data;
        last->data = tmp;

        // Re-init second node to head for next iteration.
        last = sList;

        // First node to swap - Kth node.
        first = first->next;
    }

	// Print the (essentially reversed) list.
	cout << "K-swapped list is:" << endl;
    printList(sList);

    return;
}


// ******************************************************* 3 *******************************************************
void interlaceTwoSinglyLinkedLists()
{
    cout << "Problem: Interlacing 2 linked lists, starting with the first node of the first list." << endl;

    // Build 2 vectors of elements from user input - one for each list.
    vector<int> elements1 = buildVectorOfElements();
    vector<int> elements2 = buildVectorOfElements();

    // Construct singly linked list from the built vector.
    Node* sList1 = createSinglyLinkedList(elements1);
    Node* sList2 = createSinglyLinkedList(elements2);
    if (sList1 == nullptr || sList2 == nullptr)
    {
        cout << "Uh oh....list creation failed." << endl;
        return;
    }

    // Print both just to see what's up.
	cout << "Both input lists:" << endl;
    printList(sList1);
    printList(sList2);

    // Let new list start with list1 (because I get to decide in this private test environment; why not?).
    Node* head = sList1;
    
    // Run through the 2 lists while both have elements.
    while (sList1->next != nullptr && sList2->next != nullptr)
    {
        // Temporary pointers to the next nodes of both lists.
        Node* tmp1 = sList1->next;
        Node* tmp2 = sList2->next;

        // Insert 1 list2 node into list1.
        sList1->next = sList2;
        sList2->next = tmp1;

        // Move list2 to next list2 node, move list1 node to next list1 element after list2's node insertion.
        sList1 = tmp1;
        sList2 = tmp2;
    }

    // One element left in list 2; append it, then the rest of list1 and call it a day.
    if (sList1->next != nullptr)
    {
        // We're fine, head is pointer at list1 anyway; insert last list2 node.
        Node* tmp = sList1->next;
        sList1->next = sList2;
        sList2->next = tmp;
    }

	// List 1 is out of elements, but list 2 has more; append the rest of list2 to list1.
    if (sList2->next != nullptr)
    {
        // Append the rest of list2 to list1.
        sList1->next = sList2;
    }

	// Print the interlaced, zipped-up list ensemble.
	cout << "Interlaced list:" << endl;
    printList(head);

    return;
}


// ******************************************************* 4 *******************************************************
void reverseIntegerAsListInPlace(Node* subProblemList)
{
    Node* list;
    bool isSubProblem = false;

    if (subProblemList != nullptr)
    {
		// Plot twist - problem being used as a sub-problem; list already exists! No need for any prints.
		cout << "A certain other problem is being used as a sub-problem for this one...brownie points if you can guess which." << endl;
        list = subProblemList;
		isSubProblem = true;
    }
    else
    {
        cout << "Problem: Reverse an int-represented-as-a-singly-linked-list in-place." << endl;

        // Build vector of elements from user input.
        vector<int> elements = buildVectorOfElements();

        // Construct singly linked list from the built vector.
        list = createSinglyLinkedList(elements);
        if (list == nullptr)
        {
            cout << "Uh oh....list creation failed." << endl;
            return;
        }
    }

	// Print the input list (no need if sub-problem use case though).
    if (!isSubProblem)
    {
        cout << "Input list is:" << endl;
        printList(list);
    }

	// Only manipulate a tmp pointer to the list, so that the head of the list can be used to print at the end.
    int sum = 0;
    Node* tmp = list;
    
	// Iterate over the list to find the number represented by the list.
    while (tmp != nullptr)
    {
        sum = (sum * 10) + tmp->data;
        tmp = tmp->next;
    }

	// Iterate over the list again, but this time to re-write it reverse using math magic.
    tmp = list;
    while (tmp != nullptr)
    {
        tmp->data = sum % 10;
        sum = sum / 10;
        tmp = tmp->next;
    }

	// Print the reversed list (no need if sub-problem use case though).
    if (!isSubProblem)
    {
        cout << "Reverse list in place:" << endl;
        printList(list);
    }

    return;
}


// ******************************************************* 5 *******************************************************
Node* sumOfLists(int sum)
{
    // Base case.
    if (sum/10 == 0)
    {
        Node* last = new Node(sum % 10);
        return last;
    }

    Node* head = new Node(sum % 10);
    head->next = sumOfLists(sum/10);

    return head;
}

void addTwoIntegersAsLists()
{
    cout << "Problem: Add 2 numbers represented as singly linked lists." << endl;

    // Build 2 vectors of elements from user input - one for each list.
    vector<int> elements1 = buildVectorOfElements();
    vector<int> elements2 = buildVectorOfElements();

    // Construct singly linked list from the built vector.
    Node* sList1 = createSinglyLinkedList(elements1);
    Node* sList2 = createSinglyLinkedList(elements2);
    if (sList1 == nullptr || sList2 == nullptr)
    {
        cout << "Uh oh....list creation failed." << endl;
        return;
    }

    // Print both just to see what's up.
    cout << "Both input lists:" << endl;
    printList(sList1);
    printList(sList2);

    // I did it two ways so....pick one.
    int method;
	cout << "I did this 2 ways - pick one: ";
    cin >> method;

    // Which way did I do it?
    if (method == 1)
    {
        // Two tmp nodes to iterate over the two lists.
        Node* tmp1 = sList1;
        Node* tmp2 = sList2;

        int l1 = 0;
        int l2 = 0;

        // Find numerical value of list1.
        while (tmp1 != nullptr)
        {
            l1 = (l1 * 10) + tmp1->data;
            tmp1 = tmp1->next;
        }
        // Find numerical value of list2.
        while (tmp2 != nullptr)
        {
            l2 = (l2 * 10) + tmp2->data;
            tmp2 = tmp2->next;
        }

        // Add the actual values (re-use l1).
        l1 = l1 + l2;
        cout << "Sum of lists in number-form is: " << l1 << endl;

        // Reverse the numer (re-use l2...don't forget to re-init it!).
        l2 = 0;
        while (l1)
        {
            l2 = (l2 * 10) + (l1 % 10);
            l1 = l1 / 10;
        }

        // Construct list for l3 by passing in the reverse.
		cout << "Sum of lists as a list is: " << endl;
        printList(sumOfLists(l2));
    }
    else if (method == 2)
    {
        // Reverse both lists in place.
        reverseIntegerAsListInPlace(sList1);
        reverseIntegerAsListInPlace(sList2);

		// Find size of both lists to find longer one; use tmp nodes to iterate over lists.
        Node* tmp1 = sList1;
        Node* tmp2 = sList2;
        int size1 = 0, size2 = 0;

        while (tmp1 != nullptr)
        {
            size1++;
            tmp1 = tmp1->next;
        }
        while (tmp2 != nullptr)
        {
            size2++;
            tmp2 = tmp2->next;
        }

        // Reset to heads.
        tmp1 = sList1;
        tmp2 = sList2;

        // Based on which is longer, use longer one to store sum.
        // And then reverse that longer list in-place.
        int sum, rem = 0;
        if (size1 > size2)
        {
			// Add corresponding nodes of both lists, and store sum in list1's nodes; carry over any carry into the next sum-op.
            while (tmp2 != nullptr)
            {
                sum = tmp1->data + tmp2->data;
                tmp1->data = (sum + rem) % 10;
                rem = sum / 10;

                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }

			// If there's a carry, pass it on and finish the rest of list1.
            while (tmp1 != nullptr)
            {
                tmp1->data = tmp1->data + rem;
                rem = 0;

                tmp1 = tmp1->next;
            }

            // Now print the result list, after re-reversing.
            reverseIntegerAsListInPlace(sList1);
            cout << "Sum of lists as a list is: " << endl;
            printList(sList1);
        }
        else if (size2 > size1)
        {
            // Add corresponding nodes of both lists, and store sum in list2's nodes; carry over any carry into the next sum-op.
            while (tmp1 != nullptr)
            {
                sum = tmp1->data + tmp2->data;
                tmp2->data = (sum % 10) + rem;
                rem = sum / 10;

                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }

            // If there's a carry, pass it on and finish the rest of list2.
            while (tmp2 != nullptr)
            {
                tmp2->data = tmp2->data + rem;
                rem = 0;

                tmp2 = tmp2->next;
            }

            // Now print the result list, after re-reversing.
            reverseIntegerAsListInPlace(sList2);
            cout << "Sum of lists as a list is: " << endl;
            printList(sList2);
        }
    }
    else
    {
        cout << "I only have 1 of 2 ways my friend - '1' or '2'. Your choice was neither." << endl;
    }

    return;
}