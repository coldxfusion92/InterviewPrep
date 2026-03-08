#pragma once

/*
*   TreeHelpers.h
*/

// Headers.
#include <iostream>
#include <vector>

// Namespaces.
using namespace std;

// Structure for a binary tree.
struct bTree
{
    // Data and children.
    int data = 0;
    bTree* left = nullptr;
    bTree* right = nullptr;

    // bTree constructor.
	bTree(int iData) : data(iData), left(nullptr), right(nullptr) {}
};

// F'n for basic DFS - in, pre and post order - traversals.
void inOrder(bTree* root, vector<int>orderList = {});
void preOrder(bTree* root, vector<int>orderList = {});
void postOrder(bTree* root, vector<int>orderList = {});

// F'n to return height of a tree.
int heightOfBTree(bTree* root);

// F'n to create a custom tree for testing.
bTree* createCustomBinaryTree();