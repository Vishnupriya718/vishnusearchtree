#include <iostream>
#include "bst.h"

using namespace std;

int main() {

    Node* root = NULL;

    int number;

    cout << "Enter numbers (0 to stop): ";

    // Read numbers separated by spaces
    while (cin >> number && number != 0) {

        if (number >= 1 && number <= 999) {
            root = insert(root, number);
        }
    }

    cout << "Numbers inserted.\n";

    return 0;
}
