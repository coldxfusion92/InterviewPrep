/*
*   LinkedListSolutions.cpp
*/

// Headers.
#include "TreeSolutions.h"

// ******************************************************* 1 *******************************************************
void traversalType()
{
	
	cout << "Problem: 3 ways to DFS-style traverse a binary tree." << endl;

	// Create a sample tree to traverse.
	bTree* root = createCustomBinaryTree();

	// Choose which way.
	int iChoice;
	
	cout << "1. In Order" << endl << "2. Pre Order" << endl << "3. Post Order" << endl << "Traversal Option: ";
	cin >> iChoice;
	switch (iChoice)
	{
	case 1:
		inOrder(root);
		break;
	case 2:
		preOrder(root);
		break;
	case 3:
		postOrder(root);
		break;
	}
	cout << endl << "Brownie points if you can now re-construct the tree based on that traversal data:" << endl;
	cin >> iChoice;
	cout << "Jk. This was just about traversal. We're done here." << endl;

	return;
}


// ******************************************************* 2 *******************************************************
void levelOrderTraversal()
{
	cout << "Problem: Level order traverse (BFS) a binary tree." << endl;

	vector<vector<bTree*>> bfsList;

	// Create a sample tree to traverse.
	bTree* root = createCustomBinaryTree();

	// Queue to keep track of nodes at each level; push an empty vector to start, then push root into it.
	queue<vector<bTree*>> levelOrderQ;
	levelOrderQ.push({});
	levelOrderQ.front().push_back(root);

	// Run until queue is empty, which means we've traversed all levels of the tree.
	while (!levelOrderQ.empty())
	{
		// Get the current level's nodes, push them into the bfsList, and pop the level from the queue.
		vector<bTree*> cur = levelOrderQ.front();
		bfsList.push_back(cur);
		levelOrderQ.pop();
		levelOrderQ.push({});
		
		// Iterate over the current level's nodes, and push their children into the queue for the next level.
		for (bTree* node : cur)
		{
			//cout << node->data << " ";
			if (node->left)
				levelOrderQ.front().push_back(node->left);
			if (node->right)
				levelOrderQ.front().push_back(node->right);
		}

		// If the next level is empty, pop it from the queue so that we know we're done.
		if (levelOrderQ.front().empty())
			levelOrderQ.pop();
	}

	// We know how many levels we have, since we pushed in nodes by-level instead of just pushing in all nodes into the queue.
	// The number of levels is the size of bfsList.
	// Just a fancy way of knowing the added details of which specific nodes in each level and how many nodes each level has.
	cout << "Max level of tree is: " << bfsList.size() << endl;
	cout << "Tree levels are:" << endl;

	// Print the levels of the tree as per bfsList.
	int levelCount = 0;
	for (auto level : bfsList)
	{
		cout << "Level " << levelCount++ << ": " << endl;
		for (auto node : level)
			cout << node->data << " ";
		cout << endl;
	}

	return;
}


// ******************************************************* 3 *******************************************************
bool isBalancedInefficient(bTree* node)
{
	// Base case: if node is null, it's balanced.
	if (node == nullptr)
		return true;

	// Check if the height difference between left and right subtrees is more than 1; if so, it's unbalanced.
	if (abs(heightOfBTree(node->left) - heightOfBTree(node->right)) > 1)
		return false;

	// Check if left and right subtrees are balanced; if not, it's unbalanced.
	if (!isBalancedInefficient(node->left) || !isBalancedInefficient(node->right))
		return false;

	return true;
}

int heightOrUnbalanced(bTree* node)
{
	// Base case: if node is null, it's balanced.
	if (node == nullptr)
		return 0;

	// Basically height calculation of both children - 
	// except if we get -1 back from either, we know the tree is unbalanced and can return -1 immediately without doing any more work.
	int leftHeight = heightOrUnbalanced(node->left);
	if (leftHeight == -1)
		return -1;
	int rightHeight = heightOrUnbalanced(node->right);
	if (rightHeight == -1)
		return -1;

	// Insert this fancy step into basically what is essentially a height calculation
	// So that we can calculate on the fly whether the tree is unbalanced at any point, and if so, return -1 to indicate that it's unbalanced.
	if (abs(leftHeight - rightHeight) > 1)
		return -1;

	return (max(leftHeight, rightHeight) + 1);
}

void isBinaryTreeBalanced()
{
	cout << "Problem: Check if a binary tree is balanced or not." << endl;
	
	// Create a sample tree to test on.
	bTree* root = createCustomBinaryTree();

	int iChoice = 0;
	cout << "Want the scenic route or the express route?" << endl;
	cout << "1. Scenic route (inefficient, but straightforward; O(n)^2 complexity)" << endl;
	cout << "2. Express route (efficient, but also calculates the height along the way; O(n) complexity...it's a 2-fer)" << endl;
	cin >> iChoice;

	if (iChoice == 1)
	{
		// Here's the thing, this helper will do O(n) work to calculate the height of the tree...
		// and then we call it for every node in the tree, so this is O(n^2) time complexity. Not the best.
		if (isBalancedInefficient(root))
			cout << "The tree is balanced." << endl;
		else
			cout << "The tree is not balanced." << endl;
	}
	else if (iChoice == 2)
	{
		// However, we can do better by calculating the height of the tree and whether it's balanced at the same time
		// So that we only do O(n) work total.
		int heightorUnbalanced = heightOrUnbalanced(root);
		if (heightorUnbalanced != -1)
			cout << "The tree is balanced AND the height is: " << heightorUnbalanced << endl;
		else
			cout << "The tree is not balanced." << endl;
	}
	else
	{
		cout << "I only have 1 of 2 ways my friend - '1' or '2'. Your choice was neither." << endl;
	}

	return;
}