#include "SinglyLinkedUnsortedList.h"
#include <iostream>
#include <unordered_map>

using namespace std;

SinglyLinkedUnsortedList::~SinglyLinkedUnsortedList()
{
	SinglyNode* current = headNode;
	while (current != nullptr) {
		SinglyNode* nextNode = current->successor;
		delete current;
		current = nextNode;
	}
}

SinglyNode* SinglyLinkedUnsortedList::search(int value)
{
	SinglyNode* current = headNode;
	while (current != nullptr) {
		if (current->value == value) {
			return current;
		}
		current = current->successor;
	}
	
	return nullptr;
}

void SinglyLinkedUnsortedList::insert(int value)
{
	headNode = new SinglyNode{ ++count, value, headNode };
}

bool SinglyLinkedUnsortedList::remove(SinglyNode* item)
{
	if (!headNode || !item) return false;

	if (headNode == item) { // head node is the item to remove
		SinglyNode* temp = headNode;
		headNode = headNode->successor;
		delete temp;
		return true;
	}

	SinglyNode* current = headNode;
	while (current->successor != nullptr) {
		if (current->successor == item) {
			SinglyNode* temp = current->successor;
			current->successor = temp->successor;
			delete temp;
			return true;
		}
		current = current->successor;
	}

	return false;
}

SinglyNode* SinglyLinkedUnsortedList::maxValue()
{
	if (!headNode) return nullptr;

	SinglyNode* maxNode = headNode;
	SinglyNode* current = headNode->successor;
	while (current != nullptr) {
		if (current->value > maxNode->value) {
			maxNode = current;
		}
		current = current->successor;
	}
	return maxNode;
}

SinglyNode* SinglyLinkedUnsortedList::minValue()
{
	if (!headNode) return nullptr;

	SinglyNode* minNode = headNode;
	SinglyNode* current = headNode->successor;
	while (current != nullptr) {
		if (current->value < minNode->value) {
			minNode = current;
		}
		current = current->successor;
	}
	return minNode;
}

int SinglyLinkedUnsortedList::predecessor(int x)
{
	if (!headNode) return -1; //head node doesnt exist

	SinglyNode* current = headNode;
	if (current->value == x) return -2; //no predecessor since it is the head node

	while (current != nullptr) {
		if (current->successor != nullptr && current->successor->value == x) return current->value;
		current = current->successor;
	}

	return -3; // could not find node with value x
}

int SinglyLinkedUnsortedList::successor(int x)
{
	SinglyNode* temp = search(x);
	if (temp != nullptr && temp->successor != nullptr) {
		return temp->successor->value;
	}
	return -1;
}

void SinglyLinkedUnsortedList::printList() const
{
	int count = 0;
	SinglyNode* current = headNode;
	while (current != nullptr) {
		cout << "Node " << count <<": " << current->value << endl;
		current = current->successor;
		++count;
	}
}
