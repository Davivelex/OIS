#include <iostream>

#define MAXN 1000

using namespace std;

int N, A;
long long E = 1, B = 1;

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> A;
        E += B * A;
        B = B * A;
    }

    cout << E;

    return 0;
}