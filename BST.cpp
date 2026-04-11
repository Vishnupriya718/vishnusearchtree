#include <iostream>
#include "bst.h"

using namespace std;

// Create a new node
Node* createNode(int value) {

    Node* newNode = new Node;

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert into bst
Node* insert(Node* root, int value) {

    // If tree empty
    if (root == NULL) {
        return createNode(value);
    }

    // Go left
    if (value < root->data) {
        root->left =
            insert(root->left, value);
    }

    // Go right
    else if (value > root->data) {
        root->right =
            insert(root->right, value);
    }

    return root;
}

// Search for a value in the tree
bool search(Node* root, int value) {

    // If tree empty
    if (root == NULL) {
        return false;
    }

    // Found the number
    if (root->data == value) {
        return true;
    }

    // Search left
    if (value < root->data) {
        return search(root->left, value);
    }

    // Search right
    return search(root->right, value);
}
