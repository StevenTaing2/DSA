#include "BinarySearchTree.h"
#include <iostream>
#include <cstdlib>

using namespace std;

BinarySearchTree::~BinarySearchTree()
{
    free_tree(root);
}

void BinarySearchTree::free_tree(BSTNode* node) {
    if (!node) return;
    free_tree(node->left);
    free_tree(node->right);
    delete node;
}

BSTNode* BinarySearchTree::search_tree(BSTNode* current, int value)
{
    if (current == nullptr) return nullptr;

    if (current->value == value) return current;
   
    if (value < current->value) {
        return search_tree(current->left, value);
    }
    else {
        return search_tree(current->right, value);
    }
}

BSTNode* BinarySearchTree::minimum(BSTNode* t)
{
    BSTNode* min;

    if (t == nullptr) return nullptr;

    min = t;
    while (min->left != nullptr) min = min->left;

    return min;
}

BSTNode* BinarySearchTree::maximum(BSTNode* t)
{
    BSTNode* max;

    if (t == nullptr) return nullptr;

    max = t;
    while (max->right != nullptr) max = max->right;

    return max;
}

void BinarySearchTree::traverse_tree(BSTNode* l)
{
    if (l != nullptr) {
        traverse_tree(l->left);
        cout << "Value of node is: " << l->value << endl;
        traverse_tree(l->right);
    }
}

void BinarySearchTree::insert_tree(BSTNode** node, int x, BSTNode* parent)
{
    BSTNode* temp;

    if (*node == nullptr) {
        temp = new BSTNode();
        temp->value = x;
        temp->left = temp->right = nullptr;
        temp->parent = parent;
        *node = temp;
        return;
    }

    if (x < (*node)->value) {
        insert_tree(&((*node)->left), x, *node);
    }
    else {
        insert_tree(&((*node)->right), x, *node);
    }
}

void BinarySearchTree::delete_tree(BSTNode** l, int x, BSTNode* parent)
{
    BSTNode* temp = *l;

    if (temp == nullptr) return;

    if (x < temp->value) { 
        delete_tree(&(temp->left), x, temp);
    }
    else if (x > temp->value) {
        delete_tree(&(temp->right), x, temp);
    }
    else {
        if (temp->left == nullptr && temp->right == nullptr) { // 0 child nodes
            delete temp;
            *l = nullptr;
        }
        else if (temp->left == nullptr || temp->right == nullptr) { // 1 child nodes
            BSTNode* childNode = (temp->left == nullptr) ? temp->right : temp->left;
            childNode->parent = parent;
            delete temp;
            *l = childNode;
        }
        else { // 2 child nodes
            BSTNode* successor = minimum(temp->right);
            temp->value = successor->value;
            delete_tree(&(temp->right), successor->value, temp);

        }
    }
}
