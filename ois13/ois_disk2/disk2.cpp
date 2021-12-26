#include <iostream>

#define MAXN 100000

using namespace std;

int N, T;
int A[MAXN], B[MAXN];

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N >> T;
    for(int i=0; i<N; i++) {
        cin >> A[i] >> B[i];
    }

    for(int i=0; i<N-1; i++) {
        if (24 - B[i] + A[i] >= T) {
            cout << i;
            return 0;
        }
    }

    cout << -1;

    return 0;
}