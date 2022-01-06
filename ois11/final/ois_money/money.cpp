#include <bits/stdc++.h>

#define MAXN 200000

using namespace std;

int N, M, A, B, C, K = 0;
int money[MAXN];

int main() {
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &N, &M);

    for(int i=0; i<M; i++) {
        scanf("%d %d %d", &A, &B, &C);
        money[B] += C;
        money[A] -= C;
    }

    for(int i=1; i<N; i++) if(money[i] != 0) K++;

    cout << K << endl;
    for(int i=1; i<N; i++) {
        if (money[i] > 0) {
            printf("%d 0 %d\n", i, money[i]);
        } else if (money[i] < 0) {
            printf("0 %d %d\n", i, -money[i]);
        }
    }

    return 0;
}