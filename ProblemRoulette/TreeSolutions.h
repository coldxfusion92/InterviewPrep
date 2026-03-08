#pragma once

/*
*   LinkedListHelpers.h
*/

// Headers.
#include "TreeHelpers.h"
#include "queue"

// Problem 1: In, pre and post order traversals.
void traversalType();

// Problem 2: BFS travseral of a binary tree (level order traversal).
void levelOrderTraversal();

// Problem 3: Find out if a binary tree is balanced.
// 2 helper f'ns (neither are exported) - one to calculate height and determine if unbalanced on the fly, 
// and one inefficient one that calculates height at each node and checks for balance at each node separately.
void isBinaryTreeBalanced();				// Main
// int heightOrUnbalanced(bTree* node);		// Helper 1
// bool isBalancedInefficient(bTree* node);	// Helper 2