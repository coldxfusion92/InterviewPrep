/*
*   LinkedListHelpers.cpp
*/

// Headers.
#include "TreeHelpers.h"

bTree* createCustomBinaryTree()
{
	// Create a sample tree to traverse.
	bTree* root = new bTree(1);
	root->left = new bTree(2);
	root->right = new bTree(3);
	root->left->left = new bTree(4);
	root->right->left = new bTree(5);
	root->right->right = new bTree(6);
	root->left->left->left = new bTree(7);
	root->left->left->left->right = new bTree(8);

	return root;
}

void inOrder(bTree* root, vector<int>orderList)
{
	// Base case: if root is null, done traversing this branch.
	if (root == nullptr)
		return;

	inOrder(root->left, orderList);
	cout << root->data << " ";
	orderList.push_back(root->data);
	inOrder(root->right, orderList);

	return;
}

void preOrder(bTree* root, vector<int>orderList)
{
	// Base case: if root is null, done traversing this branch.
	if (root == nullptr)
		return;

	cout << root->data << " ";
	orderList.push_back(root->data);
	preOrder(root->left, orderList);
	preOrder(root->right, orderList);

	return;
}

void postOrder(bTree* root, vector<int>orderList)
{
	// Base case: if root is null, done traversing this branch.
	if (root == nullptr)
		return;

	postOrder(root->left, orderList);
	postOrder(root->right, orderList);
	cout << root->data << " ";
	orderList.push_back(root->data);

	return;
}

int heightOfBTree(bTree* root)
{
	// Base case.
	if (root == nullptr)
		return 0;

	int leftHeight = heightOfBTree(root->left);
	int rightHeight = heightOfBTree(root->right);

	return max(leftHeight, rightHeight) + 1;
}