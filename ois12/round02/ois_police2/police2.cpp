#include <iostream>

#define MAXN 100000

using namespace std;

int N;
int adj[MAXN], number[MAXN];

int search(int start) {
    int prev, node = start, dist = 1;

    while(number[node] == 0) {
        number[node] = dist++;

        prev = node;
        node = adj[node];
    }

    return number[prev] - number[node] + 1;
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> adj[i];
        number[i] = 0;
    };

    int max_group = 0;

    for(int i=0; i<N; i++) {
        if (number[i] != 0) continue;
        max_group = max(max_group, search(i));
    }

    cout << max_group;
}