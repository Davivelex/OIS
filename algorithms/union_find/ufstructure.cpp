#include <algorithm>
#include <iostream>
#include <vector>

#define MAXN 10000

using namespace std;

struct arc {
    int from, to;
    long long cost;
};

int N, M, A, B, C;
int len[MAXN], adj[MAXN];
vector<arc> arcs;

struct UF {
    static int find(int node) {
        while(node != adj[node]) node = adj[node];
        return node;
    };

    static bool disjoint(int a, int b) {
        return find(a) != find(b);
    };

    static void join(int a, int b) {
        a = find(a);
        b = find(b);
        if (len[a] >= len[b]) {
            len[a] += len[b];
            adj[b] = a;
        } else {
            len[b] += len[a];
            adj[a] = b;
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N >> M;
    for(int i=0; i<M; i++) {
        cin >> A >> B >> C;
        arcs.push_back({A, B, C});
        adj[A] = A;
        adj[B] = B; 
    }

    sort(arcs.begin(), arcs.end(), [](const arc &lhs, const arc &rhs) {
        return lhs.cost < rhs.cost;
    });

    long long total_cost = 0;
    vector<arc> used_arcs;

    for(int i=0; i<M; i++) {
        if(used_arcs.size() == N - 1) break;
        if (UF::disjoint(arcs[i].from, arcs[i].to)) {
            UF::join(arcs[i].from, arcs[i].to);
            total_cost += arcs[i].cost;
            used_arcs.push_back(arcs[i]);
        }
    }

    cout << total_cost << endl;
    for(arc arc : used_arcs) {
        cout << arc.from << " " << arc.to << endl;
    }
    return 0;
}