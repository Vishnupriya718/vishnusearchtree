#include <iostream>
#include "bst.h"

using namespace std;

int main() {

    Node* root = NULL;

    char command;
    int number;

    cout << "Commands:\n";
    cout << "A number → Add\n";
    cout << "R number → Remove\n";
    cout << "P → Print\n";
    cout << "Q → Quit\n";

    while (true) {

        cin >> command;

        // Add
        if (command == 'A') {

            cin >> number;
            root = insert(root, number);
        }

        // Remove
        else if (command == 'R') {

            cin >> number;
            root = removeNode(root, number);
        }

        // Print
        else if (command == 'P') {

            printTree(root, 0);
        }

        // Quit
        else if (command == 'Q') {

            break;
        }
    }

    return 0;
}
