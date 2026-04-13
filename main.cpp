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
    cout << "S number → Search\n";
    cout << "P → Print\n";
    cout << "Q → Quit\n";
    cout << "I numbers → Insert multiple\n";
    while (true) {

        cout << "\nEnter command: ";
        cin >> command;
  
        // insert multiple numbers
	if (command =='I') {

	    cout << "Enter numbers (0 to stop): "; 

	    while (cin >> number && number != 0) {

	       if (number >= 1 && number <= 999) {
	           root = insert(root, number);
	       }
	       else {
		 cout << " Number must be 1-999\n";

	       }
	    }
	}    


	// ADD
        if (command == 'A') {

            cin >> number;

            if (number >= 1 && number <= 999) {
                root = insert(root, number);
            }
            else {
                cout << "Number must be 1-999\n";
            }
        }

        // REMOVE
        else if (command == 'R') {

            cin >> number;
            root = removeNode(root, number);
        }

        // SEARCH
        else if (command == 'S') {

            cin >> number;

            if (search(root, number)) {
                cout << "Found\n";
            }
            else {
                cout << "Not found\n";
            }
        }

        // PRINT
        else if (command == 'P') {

            cout << "\nTree:\n";
            printTree(root, 0);
        }

        // QUIT
        else if (command == 'Q') {

            break;
        }

        else {
            cout << "Invalid command\n";
        }
    }
    deleteTree(root);

    return 0;
}
