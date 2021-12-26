#include <iostream>

using namespace std;

class node {
    public:
        int value;
        node *prev, *next;
} *limit;

void stamp(node *first, node *current) {
    cout << first << " => ";

    while (first != limit) {
        if (first == current) {
            cout << "[" << first->value << "] ";
        } else cout << first->value << " ";
        first = first->next;
    }

    cout << endl;
}