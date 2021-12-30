#include <algorithm>
#include <iostream>
#include <vector>

#define MAXN 100000

using namespace std;

struct road {
    int from, to, cost;
};

int N, M, A, B, R, node_count, i;
vector<vector<int>> graph(MAXN, vector<int>());
vector<bool> visited(MAXN, false);
vector<road> roads;

void dfs(int node) {
    if (visited[node]) return;

    visited[node] = true;
    node_count++;

    for(int next : graph[node]) {
        if (!visited[next]) dfs(next);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> N >> M;
    for(int i=0; i<M; i++) {
        cin >> A >> B >> R;
        roads.push_back({A, B, R});
    }

    sort(roads.begin(), roads.end(), [](const road &left, const road &right) {
        return left.cost > right.cost;
    });

    visited[roads[0].from] = true;
    visited[roads[0].to] = true;
    node_count = 2;

    for(i=1; i<M; i++) {
        if (!visited[roads[i].from] && !visited[roads[i].to]) {
            graph[roads[i].from].push_back(roads[i].to);
            graph[roads[i].to].push_back(roads[i].from);
        } else if (visited[roads[i].from] || visited[roads[i].to]) {
            dfs(roads[i].from);
            dfs(roads[i].to);
        }

        if (node_count == N) break;
    }

    if (i == M) cout << roads[i-1].cost;
    else cout << roads[i].cost;
}