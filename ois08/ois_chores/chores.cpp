#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 100000

using namespace std;

int N, A, B;
vector<vector<int>> graph(MAXN, vector<int>());
vector<bool> visited(MAXN, false);
vector<int> dist(MAXN, 0);

int dfs(int node) {
    if (visited[node]) return dist[node];
    visited[node] = true;

    int max_road = 0;
    for (int next : graph[node]) {
        if (dist[next] == 0) dist[next] = dist[node] + 1; 
        max_road = max(max_road, dfs(next));
    }

    return max_road;
}


int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    cout << dfs(0);

    cout << dist[6];

    return 0;
}