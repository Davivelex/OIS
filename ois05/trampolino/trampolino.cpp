#include <iostream>
#include <vector>
#include <queue>

#define INF INT32_MAX
#define MAXN 100000

using namespace std;

int N;
int E[MAXN];
vector<int> dist(MAXN+1, INF);

struct order {
    bool operator()(const int &a, const int &b) {
        return dist[a] > dist[b];
    }
};

priority_queue<int, vector<int>, order> visit;
vector<bool> visited(MAXN+1, false);

void dijkstra(int start) {
    dist[start] = 0;
    visit.push(start);

    while (!visit.empty()) {
        int node = visit.top();
        visit.pop();

        if(visited[node]) continue;
        visited[node] = true;

        for(int jump=1; jump<=E[node]; jump++) {
            int next = node + jump;

            if (next <= N && dist[next] > dist[node] + 1) {
                dist[next] = dist[node] + 1;

                if (next == N) break;

                visit.push(next);
            }
        }
    }
    
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &E[i]);

    dijkstra(0);

    printf("%d", dist[N]);

    return 0;
}