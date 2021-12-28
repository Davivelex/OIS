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

#define MAXN 10000

using namespace std;

typedef struct arc_t {
    int from, to, cost, explode;
} arc;

vector<long long> distances(MAXN, INT64_MAX);

struct order {
    bool operator()(const int &left, int &right) {
        return distances[left] > distances[right];
    } 
};

vector<vector<arc>> graph(MAXN, vector<arc>());
//priority_queue<int, vector<int>, order> visit;
queue<int> visit;
vector<bool> visited(MAXN, false);
vector<int> prec(MAXN, -1);

int N, M, T, A, B, C, E;

void dijktra(int start) {
    visit.push(start);
    distances[start] = 0;

    while(!visit.empty()) {
        int node = visit.front();
        visit.pop();

        for(arc next : graph[node]) {
            if (distances[next.from] + next.cost < distances[next.to]) {
                if (distances[next.from] + next.cost >= T) {
                    visit.push(next.from);
                    continue;
                }
                distances[next.to] = distances[next.from] + next.cost;
                prec[next.to] = next.from;
            }
            visit.push(next.to);
        }

        visited[node] = true;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> N >> M >> T;
    for(int i=0; i<M; i++) {
        cin >> A >> B >> C >> E;
        graph[A].push_back({A, B, C, E});
    }

    dijktra(0);
    
    cout << distances[N-1] << endl;
}