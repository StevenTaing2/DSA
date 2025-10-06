#pragma once

struct BSTNode {
	int value;
	BSTNode* parent;
	BSTNode* left;
	BSTNode* right;
};

class BinarySearchTree
{
public:
	BSTNode* root;

	BinarySearchTree() :
		root{ nullptr } {
	}
	~BinarySearchTree();
	void free_tree(BSTNode* node);

	BSTNode* search_tree(BSTNode* current, int value);
	BSTNode* minimum(BSTNode* t);
	BSTNode* maximum(BSTNode* t);
	void traverse_tree(BSTNode* l);
	void insert_tree(BSTNode**l, int x, BSTNode* parent);
	void delete_tree(BSTNode** l, int x, BSTNode* parent);
	
};

