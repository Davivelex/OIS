#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define INF INT32_MAX
#define MAXN 100000

using namespace std;

struct country {
    int index, visa_price;
    vector<int> embassies;
};

struct travel {
    int from, to, price;
    bool visited;
};

int N, V, K, L, E;
int C[MAXN], T[MAXN];
vector<vector<travel>> graph(MAXN, vector<travel>());
vector<vector<int>> journey(MAXN, vector<int>());
vector<bool> visas(MAXN, false), visited(MAXN, false);
vector<int> dist(MAXN, INF);
vector<country> countries;
vector<travel> arcs;

struct order {
    bool operator()(const int &left, const int &right) {
        return dist[left] > dist[right];
    }
};

priority_queue<int, vector<int>, order> visit;

void dijkstra(int start) {
    countries[start].visa_price = 0;
    visas[start] = true;
    visit.push(start);
    dist[start] = 0;

    while(!visit.empty()) {
        int country = visit.top();
        visit.pop();

        journey[country].push_back(country);
        for (int visa : countries[country].embassies) if (!visas[visa]) visas[visa] = true;

        for (travel &travel : graph[country]) {
            if (travel.visited) continue;

            if (visas[travel.to]) {
                travel.visited = true;

                if (dist[travel.to] > dist[travel.from] + travel.price + countries[travel.to].visa_price
                || (graph[country].size() == 1 && dist[N - 1] == INF)) {
                    dist[travel.to] = dist[travel.from] + travel.price + countries[travel.to].visa_price;
                    journey[travel.to] = journey[travel.from];
                    visit.push(travel.to);
                }
            }
        }
    }
}

void normal_dijkstra(int start) {
    visit.push(start);
    dist[start] = 0; 

    while(!visit.empty()) {
        int country = visit.top();
        visit.pop();

        //if (visited[country]) continue;
        //visited[country] = true;

        for (int visa : countries[country].embassies) if (!visas[visa]) visas[visa] = true;

        journey[country].push_back(country);

        for (travel travel : graph[country]) {
            if (visas[travel.to]) {
                if (dist[travel.to] > dist[travel.from] + travel.price + countries[travel.to].visa_price) {
                    dist[travel.to] = dist[travel.from] + travel.price + countries[travel.to].visa_price;
                    journey[travel.to] = journey[travel.from];
                    visit.push(travel.to);
                }
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> V >> K >> L;

        vector<int> E(K, 0);
        arcs.clear();

        for(int j=0; j<K; j++) cin >> E[j];
        for(int j=0; j<L; j++) cin >> C[j];
        for(int j=0; j<L; j++) cin >> T[j];
        for(int j=0; j<L; j++) graph[i].push_back({i, C[j], T[j], false});

        countries.push_back({i, V, E});
    }


    normal_dijkstra(0);

    // debug
    cout << dist[N - 1] << endl;

    cout << journey[N-1].size() << endl;
    for(int i=0; i<journey[N-1].size(); i++) cout << journey[N-1][i] << " ";
}
