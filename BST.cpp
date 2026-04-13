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
// Print tree sideways (visual representation)
void printTree(Node* root, int space) {

    // If empty, stop
    if (root == NULL) {
        return;
    }

    // Increase spacing
    space += 5;

    // Print right subtree first
    printTree(root->right, space);

    // Print current node
    for (int i = 5; i < space; i++) {
        cout << " ";
    }

    cout << root->data << endl;

    // Print left subtree
    printTree(root->left, space);
}
// Find smallest value
Node* findMin(Node* root) {

    // Go left until NULL
    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

// Remove node (Case 1 + Case 2 + Case 3)
Node* removeNode(Node* root, int value) {

    if (root == NULL) {
        return root;
    }

    // Go left
    if (value < root->data) {
        root->left =
            removeNode(root->left, value);
    }

    // Go right
    else if (value > root->data) {
        root->right =
            removeNode(root->right, value);
    }

    // Found node to delete
    else {

        // CASE 1 — No children
        if (root->left == NULL &&
            root->right == NULL) {

            delete root;
            return NULL;
        }

        // CASE 2 — One child (right)
        else if (root->left == NULL) {

            Node* temp = root->right;
            delete root;
            return temp;
        }

        // CASE 2 — One child (left)
        else if (root->right == NULL) {

            Node* temp = root->left;
            delete root;
            return temp;
	    
        }
	// CASE 3 — Two children
	else {

            // Step 1: find successor
            Node* temp = findMin(root->right);

            // Step 2: copy value
            root->data = temp->data;

            // Step 3: delete successor
            root->right =
                removeNode(root->right,
                           temp->data);
	    
    }

  }

    return root;
}
void deleteTree(Node* root) {

    if (root == NULL) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}
