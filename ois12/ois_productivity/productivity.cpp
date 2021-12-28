#include <iostream>
#include <vector>

using namespace std;

int N, M, E, K = 0;

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N >> M >> E;
    for (int i = M; i <= N; i++) {
        K = max(K, E%i);
    }

    cout << K;
}
