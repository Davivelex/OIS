/*  +----------------------------------------------+
    |              Dijkstra Algorithm              |
    +----------------------------------------------+
    | This algorithm is useful for calculating the |
    | path with the least cost on graphs with both |
    | mono and bidirectional weighted arcs. It is  |
    | also possible to obtain the tree of minimum  |
    | paths and therefore the cheapest path.       |
    +----------------------------------------------+
    |                       @Davide Leva, Dec 2021 |
    +----------------------------------------------+
*/

#include <iostream>
#include <queue>

#define MAXN 100002

using namespace std;

typedef struct arc_t {
    int from, to, cost;
} arc;

vector<long long> distances(MAXN, INT64_MAX);

struct order {
    bool operator()(const int &left, int &right) {
        return distances[left] > distances[right];
    } 
};

vector<vector<arc>> graph(MAXN, vector<arc>());
priority_queue<int, vector<int>, order> visit;
vector<bool> visited(MAXN, false);
vector<int> prec(MAXN, -1);

void dijktra(int start) {
    visit.push(start);
    distances[start] = 0;

    while(!visit.empty()) {
        int node = visit.top();
        
        visit.pop();

        for(arc next : graph[node]) {
            if (distances[next.from] + next.cost < distances[next.to]) {
                distances[next.to] = distances[next.from] + next.cost;
                prec[next.to] = next.from;

                if (!visited[next.to]) {
                    visit.push(next.to);
                }
            }
        }

        visited[node] = true;
    }
}

int N, M, F, T, A, B, C;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> N >> M >> F >> T;
    for(int i=0; i<M; i++) {
        cin >> A >> B >> C;
        graph[A].push_back({A, B, C});
        // If the graph is bidirectional
        graph[B].push_back({B, A, C});
    }

    dijktra(F);
    
    cout << distances[T] << endl;

    // Minimum path (reverse)
    //for (int i=T; i != prec[F]; i = prec[i]) cout << i << " ";
}