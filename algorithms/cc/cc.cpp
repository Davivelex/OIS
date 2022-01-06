#include <iostream>
#include <vector>

#define MAXN 10000

using namespace std;

int N, M, A, B;
vector<vector<int>> graph(MAXN, vector<int>());
vector<vector<int>> subgraphs(MAXN, vector<int>());
vector<int> id(MAXN, 0);

void cc_dfs(int node, int new_id) {
    id[node] = new_id;

    for(int next : graph[node]) {
        if (id[next] == 0) cc_dfs(next, new_id);
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for(int i=0; i<M; i++) {
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    int new_id = 1;
    for(int i=1; i<=N; i++) {
        if (id[i] == 0) cc_dfs(i, new_id++);
    }

    for(int i=1; i<=N; i++) {
        subgraphs[id[i]].push_back(i);
    }

    for(int i=1; i<new_id; i++) {
        cout << "SUBGRAPH " << i << ": ";
        for(int j=0; j<subgraphs[i].size(); j++) {
            cout << subgraphs[i][j] << " ";
        }
        cout << endl;
    }
}