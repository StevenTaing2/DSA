#include "Queue.h"

void Queue::enqueue(int value)
{
	queue_node* qn = new queue_node{ value, nullptr };
	
	if (isEmpty()) {
		front = qn;
		back = qn;
	}
	else {
		back->next = qn;
		back = qn;
	}
}

int Queue::dequeue()
{
	if (isEmpty()) return -1;

	queue_node* temp = front;
	int temp_value = temp->value;
	front = front->next;

	if (front == nullptr) {
		back = nullptr;
	}

	delete temp;
	return temp_value;
}

bool Queue::isEmpty() {
	return front == nullptr;
}
