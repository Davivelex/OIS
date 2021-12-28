#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define INF INT32_MAX
#define MAXN 200

using namespace std;

typedef pair<int, int> ii;

const ii NO_DIR = {-1, -1};
ii moves[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int N;
char I;
map<ii, char> M;
map<ii, int> dist;
map<ii, bool> visited;
map<ii, ii> dir;

struct order {
    bool operator()(const ii &left, const ii &right) {
        return dist[left] > dist[right];
    }
};

priority_queue<ii, vector<ii>, order> visit;

void dijktra(ii start) {
    visit.push(start);
    dist[start] = 0;

    while(!visit.empty()) {
        ii node = visit.top();
        visit.pop();

        for (ii move : moves) {
            ii next = {node.first + move.first, node.second + move.second};

            if (next.first < 0 || next.first > N - 1
            || next.second < 0 || next.second > N - 1
            || M[next] == '#') continue;

            int weigth = (dir[node] != NO_DIR && dir[node] != move) ? 1 : 0;

            if (dist[next] > dist[node] + weigth) {
                dist[next] = dist[node] + weigth;
                dir[next] = move;
                if (!visited[next]) visit.push(next);
            }
        }

        visited[node] = true;
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
        cin >> I;
        M[{i, j}] = I;
        dist[{i, j}] = INF;
        dir[{i, j}] = NO_DIR;
        visited[{i, j}] = false;
    };

    dijktra({0, 0});

    if (dist[{N-1, N-1}] == INF) {
        cout << -1;
    } else cout << dist[{N-1, N-1}];

    return 0;
}