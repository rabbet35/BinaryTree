#pragma once

struct Node
{
	Node* parent = nullptr;
	Node* leftChild = nullptr;
	Node* rightChild = nullptr;
	int data = 0;
};

class BinaryTree
{
private:
	Node* root = nullptr;
	bool isEmpty = true;
	int count = 0;

	/*recursively removes all leaf nodes connected to the provided node,
	  and removes the provided node.*/
	void deleteLeafAndBranchesRecursive(Node* root);

	/*adds the provided node to the binary tree at the suitable branch.
	  recursive. Starting at the provided leaf pointer.*/
	void insertNodeRecursive(Node* parentLeaf, Node* newNode);

	/*recursively searches for a node which contains the provided value.
	  Returns true if found, else false.*/
	bool searchForValueRecursive(Node* root, int value) const;

	/*recursively searches for a node which contains the provided value.
	  if found, removes that node safely and returns true. else returns false.*/
	bool searchAndDeleteLeafRecursive(Node* root, int value);

	/*deletes the provided leaf node and re-constructs its children branches.*/
	void deleteLeaf(Node* leaf);

	/*returns the deepest left side (smallest) node under the provided root*/
	Node* getDeepestSmallestNodeRecursive(Node* root);

	/*returns the deepest right side (largest) node under the provided root*/
	Node* getDeepestLargestNodeRecursive(Node* root);

public:
	/*initializes*/
	BinaryTree(bool startWithRoot = false, int rootValue = 0);
	~BinaryTree();

	/*adds a node with the provided value to the binary tree*/
	void addNode(int value);

	/*Returns true if the binary tree contains a node with the provided value.
	  Uses binary searching.*/
	bool contains(int value) const;

	/*returns true if node with value was found and removed, 
	  else returns false.*/
	bool remove(int value);

	/*returns total count of nodes in tree*/
	int getCount();

	/*returns true if tree is empty*/
	bool getIsEmpty();

	/*returns the root of this tree*/
	Node* getRoot();

	/*prints all node data to console*/
	void print();

};
/*returns the number of child layers under the provided node.
  useful for rendering nodes.*/
int getChildCountRecursive(Node* node);

/*returns true if provided node has child*/
bool hasChild(Node* node);

/*returns true if the provided node is a right child of its parent*/
bool isRightChild(Node* node);

/*returns the count of left hand childen under the node*/
int getLeftChildCount(Node* node);

/*returns the count of right hand children under the node*/
int getRightChildCount(Node* node);