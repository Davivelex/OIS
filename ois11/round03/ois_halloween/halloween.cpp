#include <iostream>

#define MAXN 100000

using namespace std;

int N, i;
long long M, S;
int L[MAXN];

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> L[i];
        S += L[i];
    }

    M %= S;

    if (M == 0) {
        cout << N - 1;
        return 0; 
    }

    for (i=0; M > 0; i++) {
        M -= L[i];
    }

    cout << i-1;

    return 0;
}