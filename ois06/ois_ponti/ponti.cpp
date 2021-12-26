#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, K, a, b;
vector<pair<int, int>> arcs;
vector<vector<int>> graph(100000, vector<int>());
set<int> visited;

void dfs(int n) {
    visited.insert(n);
    
    for(int next : graph[n]) {
        if (find(visited.begin(), visited.end(), next) == visited.end())
            dfs(next);
    }

    return;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N >> K;
    for(int i=0; i<K; i++) {
        cin >> a >> b;
        arcs.push_back(make_pair(a, b));
        graph[a].push_back(b);
    }


    for(auto arc : arcs) {
        if (find(visited.begin(), visited.end(), arc.first) == visited.end())
            dfs(arc.first);
    }

    if (K == 0) N--;

    cout << N - visited.size() << endl;

    return 0;
}