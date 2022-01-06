#include <iostream>
#include <stack>
#include <vector>

#define MAXN 10000

using namespace std;

int N, M, A, B;
vector<vector<int>> graph(MAXN, vector<int>());
vector<bool> visited(MAXN, false);
stack<int> top_order;

void tf_dfs(int node) {
    visited[node] = true;

    for(int next : graph[node]) {
        if (!visited[next]) tf_dfs(next);
    }

    top_order.push(node);
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for(int i=0; i<M; i++) {
        cin >> A >> B;
        graph[A].push_back(B);
    }

    for(int i=1; i<=N; i++) {
        if (!visited[i]) tf_dfs(i);
    }

    while(!top_order.empty()) {
        cout << top_order.top() << " ";
        top_order.pop();
    }
    return 0;
}