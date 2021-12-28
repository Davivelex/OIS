#include <iostream>
#include <queue>

#define INF INT64_MAX
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
priority_queue<int, vector<int>, order> visit;
vector<bool> visited(MAXN, false);

int N, M, T, A, B, C, E;

void dijktra(int start) {
    visit.push(start);
    distances[start] = 0;

    while(!visit.empty()) {
        int node = visit.top();
        visit.pop();

        for(arc next : graph[node]) {
            //cout << distances[next.from] + next.cost << endl;
            if (next.explode != 1 || distances[next.from] + next.cost <= T) {
                if (distances[next.from] + next.cost < distances[next.to]) {
                    distances[next.to] = distances[next.from] + next.cost;
                }
                if(!visited[next.to]) visit.push(next.to);
            } else if(!visited[next.to]) visit.push(next.to);
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
    
    if (distances[N-1] == INF) {
        cout << -1 << endl;
    } else cout << distances[N-1] << endl;
}