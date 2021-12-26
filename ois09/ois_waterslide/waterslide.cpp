#include <iostream>
#include <vector>

#define MAXN 100000

int N, M, P;
int a, b;

using namespace std;

vector<vector<int>> graph(MAXN, vector<int>());
vector<double> people (MAXN, 0);

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N >> M >> P;
    for(int i=0; i<M; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    people[0] = 1;

    for (int node=0; node<N; node++) {
        if (graph[node].size() == 0) continue;

        for (int child : graph[node]) {
            people[child] += people[node] / graph[node].size();
        }
    }

    double value = 0;
    int pool;

    for (int i=N-P; i<N; i++) {
        if (people[i] > value) {
            value = people[i];
            pool = i;
        }
    }

    cout << pool;

    return 0;
}
