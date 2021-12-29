#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

#define MAXN 10000

using namespace std;

int N, K, A, B;
int G = 0;
vector<bool> visited(MAXN, false);
vector<vector<int>> graph(100000, vector<int>());

void dfs(int i) {
    if (visited[i]) return;
    visited[i] = true;

    for(int next : graph[i]) dfs(next);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> N >> K;
    for(int i=0; i<K; i++) {
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    for(int i=0; i<N; i++) {
        if (!visited[i]) {
            dfs(i);
            G++;
        }
    }

    cout << --G;

    return 0;
}