/*
*   LinkedList.cpp
*/

// Headers.
#include <iostream>

// Namespaces.
using namespace std;

// Structure for a node in a doubly linked list.
struct Node
{
    int data;
    Node* prev;
    Node* next;

    // Node constructor.
    Node(int iData)
    {
        data = iData;
        prev = nullptr;
        next = nullptr;
    }
};

// F'n for creating a new doubly list with 'numNodes' number of elements.
Node* createDoublyLinkedList(int numNodes)
{
    // Edge case: 0 list size is invalid.
    if (numNodes == 0)
    {
        cout << "Error: Minimum list size is 1." << endl;
        return nullptr;
    }

    cout << "Creating new doubly linked list." << endl;

    // Head node.
    Node* head = new Node(1);
    Node* tmp = head;

    // Create rest of the list.
    for (int i = 2; i <= numNodes; i++)
    {
        // Data.
        tmp->next = new Node(i);

        // Next and prev links.
        Node* prevNode = tmp;
        tmp = tmp->next;
        tmp->prev = prevNode;
    }

    return head;
}

// F'n for creating a new singly linked list with 'numNodes' number of elements starting from 'startNode'.
Node* createSinglyLinkedList(int numNodes, int startNode)
{
    // Base case - cannot have 0 nodes.
    if (numNodes == 0)
    {
        cout << "Invalid number of nodes specified." << endl;
        return nullptr;
    }

    cout << "Creating singly linked list" << endl;

    // Head node.
    Node* head = new Node(startNode++);
    Node* tmp = head;

    for (int i = 2; i <= numNodes; i++)
    {
        // Creating the list.
        tmp->next = new Node(startNode++);
        tmp = tmp->next;
    }

    return head;
}

// Helper f'n to print a list.
void printList(Node* list)
{
    Node* tmp = list;

    cout << "List is: " << endl;
    while (tmp->next != nullptr)
    {
        cout << tmp->data << " <-> ";
        tmp = tmp->next;
    }
    cout << tmp->data;

    cout << endl << "End of list." << endl << endl;
}

// Helper f'n to print list in reverse (tests doubly linked list validity).
void printListInReverse(Node* list)
{
    Node* tmp = list;

    cout << "Reverse list is: " << endl;
    
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

    cout << "End of list." << endl << endl;
}

Node* swapNodesProblem(Node* list)
{
    cout << endl << "Swapping every 2 elements in list." << endl;

    // Create new node to keep track of beginning of list post-swap.
    Node* node0 = new Node(0);
    node0->next = list;

    // Assign Node1, but also assign its prev to Node0.
    Node* node1 = list;
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

        // Swap links for the 2 elements in question.
        node1->next = node2->next;
        node2->prev = node1->prev;
        node1->prev = node2;
        node2->next = node1;

        // Clean up links on either side.
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
    int listSize = 0;

    // Retrieve user input for size of new list to create.
    cout << "Enter number of nodes in new list: ";
    cin >> listSize;

    // Create new list with listSize nodes; return 0 if size is invalid (0).
    Node* newList = createDoublyLinkedList(listSize);
    if (newList == nullptr)
        return;

    // Print the list forwards and backwards (for kicks).
    printList(newList);
    printListInReverse(newList);

    // Implement swap algorithm and print list.
    newList = swapNodesProblem(newList);
    printList(newList);

    return;
}

void interlaceTwoSinglyLinkedLists()
{
    int listSize1 = 0;
    int listSize2 = 0;
    int startNode1 = 0;
    int startNode2 = 0;

    // Retrieve user input for size of new lists to create.
    cout << "Enter number of nodes in list1: ";
    cin >> listSize1;
    cout << "Enter start node number for list1: ";
    cin >> startNode1;

    cout << "Enter number of nodes in list2: ";
    cin >> listSize2;
    cout << "Enter start node number for list2: ";
    cin >> startNode2;

    // Create two lists.
    Node* list1 = createSinglyLinkedList(listSize1, startNode1);
    Node* list2 = createSinglyLinkedList(listSize2, startNode2);

    printList(list1);
    printList(list2);

    // Let new list start with list1.
    Node* head = list1;
    
    // Interlace the 2 lists.
    while (list1->next != nullptr && list2->next != nullptr)
    {
        // Temporary pointes to the next nodes of both lists.
        Node* tmp1 = list1->next;
        Node* tmp2 = list2->next;

        // Insert 1 list2 node into list1.
        list1->next = list2;
        list2->next = tmp1;

        // Move list2 to next list2 node, move list1 node to next list1 element.
        list1 = tmp1;
        list2 = tmp2;
    }

    if (list1->next != nullptr)
    {
        // We're fine, head is pointer at list1 anyway; insert last list2 node.
        Node* tmp = list1->next;
        list1->next = list2;
        list2->next = tmp;
    }

    if (list2->next != nullptr)
    {
        // Append the rest of list2 to list1.
        list1->next = list2;
    }

    printList(head);

    return;
}

void swapKthNodes()
{
    int listSize = 0;
    int startNode = 0;

    // Retrieve user input for size of new list to create.
    cout << "Enter number of nodes in new list: ";
    cin >> listSize;
    cout << "Enter start node number for list1: ";
    cin >> startNode;

    // Create list.
    Node* list1 = createSinglyLinkedList(listSize, startNode);
    
    // Two nodes to swap.
    Node* first = list1;
    Node* last = list1;
    
    // Traverse to n/2 of list.
    for (int i = 0; i < listSize/2; i++)
    {
        // Traverse to N-Kth node.
        for (int j = 0; j < (listSize - 1) - i; j++)
        {
            last = last->next;
        }

        // Swap the data.
        int tmp = first->data;
        first->data = last->data;
        last->data = tmp;

        // Re-init second node to head for next iteration.
        last = list1;

        // First node to swap - Kth node.
        first = first->next;
    }

    printList(list1);

    return;
}

void reverseListInPlace(Node* list)
{
    int sum = 0;
    Node* tmp = list;
    
    while (tmp != nullptr)
    {
        sum = (sum * 10) + tmp->data;
        tmp = tmp->next;
    }

    tmp = list;
    while (tmp != nullptr)
    {
        tmp->data = sum % 10;
        sum = sum / 10;
        tmp = tmp->next;
    }

    cout << "Reverse list in place:" << endl;
    printList(list);
}

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

void addTwoListsHelper(Node* Originallist1, Node* Originallist2)
{
    // Vars.
    Node* list1 = Originallist1;
    Node* list2 = Originallist2;

    // Method 1.
    if (0)
    {
        int l1 = 0;
        int l2 = 0;
        int l3 = 0;
        int l4 = 0;

        // Find numerical of list1.
        while (list1 != nullptr)
        {
            l1 = (l1 * 10) + list1->data;
            list1 = list1->next;
        }
        // Find numerical of list2.
        while (list2 != nullptr)
        {
            l2 = (l2 * 10) + list2->data;
            list2 = list2->next;
        }

        // Add.
        l3 = l1 + l2;
        cout << "Sum of lists in number is: " << l3 << endl;

        // Reverse the numer.
        while (l3)
        {
            l4 = (l4 * 10) + (l3 % 10);
            l3 = l3 / 10;
        }
        cout << "Sum reverse is : " << l4 << endl;

        // Construct list for l3.
        printList(sumOfLists(l4));
    }

    // Method 2.
    if (1)
    {
        // Reverse both lists in place.
        reverseListInPlace(list1);
        reverseListInPlace(list2);

        // Find size of both lists to find longer one.
        Node* tmp1 = list1;
        Node* tmp2 = list2;
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

        tmp1 = list1;
        tmp2 = list2;

        // Based on which is longer, use longer one to store sum.
        // And then reverse that longer list in-place.
        int sum, rem = 0;
        if (size1 > size2)
        {
            while (tmp2 != nullptr)
            {
                sum = tmp1->data + tmp2->data;
                tmp1->data = (sum + rem) % 10;
                rem = sum / 10;

                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }

            while (tmp1 != nullptr)
            {
                tmp1->data = tmp1->data + rem;
                rem = 0;

                tmp1 = tmp1->next;
            }

            reverseListInPlace(list1);
        }
        else if (size2 > size1)
        {
            while (tmp1 != nullptr)
            {
                sum = tmp1->data + tmp2->data;
                tmp2->data = (sum % 10) + rem;
                rem = sum / 10;

                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }

            while (tmp2 != nullptr)
            {
                tmp2->data = tmp2->data + rem;
                rem = 0;

                tmp2 = tmp2->next;
            }

            reverseListInPlace(list2);
        }
    }
}

void addTwoLists()
{
    int listSize1 = 0;
    int listSize2 = 0;
    int startNode1 = 0;
    int startNode2 = 0;

    // Retrieve user input for size of new lists to create.
    cout << "Enter number of nodes in list1: ";
    cin >> listSize1;
    cout << "Enter start node number for list1: ";
    cin >> startNode1;

    cout << "Enter number of nodes in list2: ";
    cin >> listSize2;
    cout << "Enter start node number for list2: ";
    cin >> startNode2;

    // Create two lists.
    Node* list1 = createSinglyLinkedList(listSize1, startNode1);
    Node* list2 = createSinglyLinkedList(listSize2, startNode2);

    cout << "Both lists:" << endl;
    printList(list1);
    printList(list2);

    // Call helper.
    addTwoListsHelper(list1, list2);
}

int main()
{
    //swapEveryTwoNodesInDoublyLinkedList();
    //interlaceTwoSinglyLinkedLists();
    //swapKthNodes();
    addTwoLists();

    return 1;
}