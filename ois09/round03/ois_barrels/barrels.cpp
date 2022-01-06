#include <bits/stdc++.h>

using namespace std;

struct barrel {
    int capacity;
    int content;
    int next;
    barrel(int c, int n): capacity(c), content(0), next(n) {};
} *limit;

int N, T, C, K, U, Q;
char L;
vector<barrel> barrels;

int put(int K, int U) {
    barrel &B = barrels[U];
    if (U == N) return N;

    B.content += K;
    int O = B.content - B.capacity;

    if (O > 0) {
        B.content = B.capacity;
        return B.next = put(O, B.next);
    } else return U;
}

int main() {
    freopen("input.txt", "r", stdin);

    scanf("%d %d\n%d ", &N, &T, &C);

    barrels.push_back(barrel(C, 1));
    for(int i=1; i<N; i++) {
        scanf("%d ", &C);
        barrels.push_back(barrel(C, i+1));
    }

    for(int i=0; i<T; i++) {
        scanf("%c ", &L);
        if (L == 'P') {
            scanf("%d %d\n", &K, &U);
            put(K, U);
        } else {
            scanf("%d\n", &Q);
            printf("%d\n", barrels[Q].content);
        }
    }
}