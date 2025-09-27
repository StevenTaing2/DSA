#include "Stack.h"

void Stack::push(int item)
{
	stack_node* node = new stack_node{ item, top };
	top = node;
}

void Stack::pop()
{
	if (isEmpty()) {
		return;
	}

	stack_node* temp_node = top;
	top = top->next;
	delete temp_node;
	
}

int Stack::peekStack()
{
	if (isEmpty()) {
		return(-1);
	}

	return top->value;
}

bool Stack::isEmpty()
{
	return top == nullptr;
}