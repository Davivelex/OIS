#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 100000

using namespace std;

int N, A, B;
vector<vector<int>> graph(MAXN, vector<int>());

pair<int, int> bfs(int start) {
    vector<bool> visited(MAXN, false);
    vector<int> dist(MAXN, 0);
    queue<int> q;

    visited[start] = true;
    dist[start] = 0;
    q.push(start);

    int furthest = start;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int next : graph[node]) {
            if (visited[next]) continue;
            visited[next] = true;
            dist[next] = dist[node] + 1;
            if (dist[next] > dist[furthest]) furthest = next; 
            q.push(next);
        }
    }

    return {furthest, dist[furthest]};
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    cout << bfs(bfs(0).first).second*2;

    return 0;
}