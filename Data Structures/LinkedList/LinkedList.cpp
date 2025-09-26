#include "LinkedList.h"
#include <cstdlib> // for malloc


//recursive search of a linked list
node_list* search_list(node_list* head_node, item_type search_item)
{
	if (head_node == nullptr) return nullptr;

	if (head_node->item == search_item) return head_node;
	else return search_list(head_node->next, search_item);
}

// insert at the start of the linked list 
void insert_list(node_list** head_node, item_type insert_item)
{
	node_list* p; // temp pointer for new node

	p = (node_list*)malloc(sizeof(node_list));

	if (p != nullptr) {
		p->item = insert_item; // set temp node's value
		p->next = *head_node; // set next node of temp node to current head node
		*head_node = p; // update head node to new node
	}
	
}

//
node_list* item_ahead(node_list* head_node, node_list* target)
{
	if (head_node == nullptr || head_node->next == nullptr) return nullptr; // if node_list is less than 2, return nullptr

	if (head_node->next == target) return head_node; // return current node if next node is the target node
	else return item_ahead(head_node->next, target);
}

void delete_list(node_list** head_node, node_list **delete_item)
{
	node_list* p; // pointer to current head node
	node_list* pred; // find predecessor pointer

	p = *head_node;
	pred = item_ahead(*head_node, *delete_item);


	if (pred == nullptr) *head_node = p->next; // if the head node is the node to delete, update the head node to the next node
	else pred->next = (*delete_item)->next; ///if pred node is not the head node, skip

	free(*delete_item); // free memory used by node 
}


