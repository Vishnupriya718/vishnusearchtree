#include <iostream>
#include "bst.h"

using namespace std;

int main() {

    Node* root = NULL;

    int number;

    cout << "Enter numbers (0 to stop): ";

    // Insert numbers
    while (cin >> number && number != 0) {

        if (number >= 1 && number <= 999) {
            root = insert(root, number);
        }
    }

    // Now test searching
    cout << "Enter number to search: ";
    cin >> number;

    if (search(root, number)) {
        cout << "Number FOUND\n";
    }
    else {
        cout << "Number NOT found\n";
    }

    return 0;
}
