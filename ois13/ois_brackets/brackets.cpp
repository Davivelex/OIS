#include <iostream>

using namespace std;

int T, N, K;
int n;

class node {
    public:
        int value;
        node *prev, *next;
} *limit;

node *cut(node *node) {
    if (node->prev != limit) node->prev->next = node->next->next;
    if (node->next->next != limit) node->next->next->prev = node->prev;
    return node->prev;
}

bool is_quantum(node *node) {
    return node->prev == limit
        && node->next != limit
        && node->value == node->next->value
        && node->next->next == limit;
}

int solve() {
    cin >> N >> K;

    node *current, *prec = limit;

    for(int i=0; i<N; i++) {
        current = new node();
        cin >> current->value;
        current->prev = prec;
        if (prec != limit) prec->next = current;
        prec = current;
    }

    current->next = limit;

    for (node *i = current; i != limit; i = i->prev) {
        if (is_quantum(i)) return 1;
        if (i->next != limit && i->value == i->next->value) cut(i);
    }

    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> T;
    for(int t=0; t<T; t++) {
        cout << solve() << endl;
    }

    return 0;
}