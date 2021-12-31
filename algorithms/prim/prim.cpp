#include <iostream>
#include <vector>
#include <queue>

#define MAXN 10000

using namespace std;

struct arc {
    int from, to;
    long long cost;
};

struct MST {
    vector<arc> arcs;
    long long total_cost;
};

struct order {
    bool operator()(const arc &lhs, const arc &rhs) {
        return lhs.cost > rhs.cost;
    }
};

int N, M, A, B, C;
vector<vector<arc>> graph(MAXN, vector<arc>());
priority_queue<arc, vector<arc>, order> visit;
vector<bool> visited(MAXN, false);

MST prim(int start) {
    int node_number = 1;
    int node = start;
    MST result = {vector<arc>(), 0LL};

    while(node_number < N) {
        visited[node] = true;
        for (arc arc : graph[node]) {
            if (!visited[arc.to]) visit.push(arc);
        }

        arc arc;
        do {
            arc = visit.top();
            visit.pop();
        } while(visited[arc.to]);

        result.arcs.push_back(arc);
        result.total_cost += arc.cost;
        node_number++;
        node = arc.to;
    }

    return result;
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for(int i=0; i<M; i++) {
        cin >> A >> B >> C;
        graph[A].push_back({A, B, C});
        graph[B].push_back({B, A, C});
    }

    MST mst = prim(1);

    cout << mst.total_cost << endl;
    for(arc used_arc : mst.arcs) {
        cout << used_arc.from << " " << used_arc.to << endl;
    }
}