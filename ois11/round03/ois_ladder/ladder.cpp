#include <iostream>

#define MAXN 1000000

using namespace std;

int N, L;
int C[MAXN];

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) cin >> C[i];

    L = C[0];

    for(int i=1; i<N; i++) {
        L = max(L, C[i]-C[i-1]);
    }

    cout << L;

    return 0;
}