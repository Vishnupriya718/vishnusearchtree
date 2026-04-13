#ifndef BST_H
#define BST_H

#include "Node.h"

// Function declarations

Node* createNode(int value);

Node* insert(Node* root, int value);

bool search(Node* root, int value);

Node* removeNode(Node* root, int value);

Node* findMin(Node* root);

void printTree(Node* root, int space);

void deleteTree(Node* root);
#endif
