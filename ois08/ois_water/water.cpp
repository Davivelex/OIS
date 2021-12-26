#include <iostream>
#include <vector>

#define INF 2147483647

using namespace std;

int N;
int T = 1;
vector<bool> visited(14348907, false);


int bfs(int n, int c) {
    if (visited[n] || n > T || n <= 0) return INF;
    if (T % N == 0) return c + 2;

    visited[n] = true;
    cout << n << endl;

    return min(bfs(n-1, c+1), min(bfs(n+1, c+1), bfs(2*n, c+1)));
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N;
    while(T < N) {
        T *= 3;
    }

    cout << bfs(N, 0);

    return 0;
}