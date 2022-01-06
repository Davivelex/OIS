#include <iostream>
#include <vector>

#define INF INT32_MAX
#define MAXN 10000
#define MAXM 100000

using namespace std;

int N, M, A, B;
vector<int> height(MAXN, 0);
vector<bool> visited(MAXN, false);
vector<vector<int>> graph(MAXN, vector<int>());

int dfs(int node, int prev) {
    if (visited[node]) return node;
    visited[node] = true;

    int next = node;
    int minH = INF;
    for(int n : graph[node]) {
        if (n == prev) continue;

        if (height[n] < minH) {
            next = n;
            minH = height[n];
        }
    }

    if (minH == INF) return node;
    return dfs(next, node);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> height[i];
    for(int i=0; i<M; i++) {
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    cout << dfs(0, -1) << endl;

    return 0;
}