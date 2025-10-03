#pragma once
#include "SinglyNode.h"

class SinglyLinkedUnsortedList
{
private:
	int count;
	SinglyNode* headNode;
public:
	SinglyLinkedUnsortedList():
		count{0},
		headNode{ nullptr }
	{}
	~SinglyLinkedUnsortedList();
	SinglyNode* search(int value);
	void insert(int value);
	bool remove(SinglyNode* item);

	SinglyNode* maxValue();
	SinglyNode* minValue();
	int predecessor(int x);
	int successor(int x);
	void printList() const;
};

