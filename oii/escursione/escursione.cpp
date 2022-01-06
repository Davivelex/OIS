#include <iostream>
#include <map>
#include <queue>

#define MAXH 100
#define MAXW 100
#define INF INT32_MAX

using namespace std;

typedef pair<int, int> coo;

int T, H, W;
int A[MAXH][MAXW];
map<coo, bool> visited;
map<coo, int> danger;

struct order {
    bool operator()(const coo &lhs, const coo &rhs) {
        return danger[lhs] > danger[rhs];
    }
};

priority_queue<coo, vector<coo>, order> visit;
coo moves[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dijkstra(coo start) {
    danger[start] = 0;
    visit.push(start);

    while(!visit.empty()) {
        coo node = visit.top();
        visit.pop();

        if (visited[node]) continue;
        visited[node] = true;

        for(coo move : moves) {
            coo next = {node.first + move.first, node.second + move.second};
            if (visited[next]) continue;
            int new_danger = abs(A[node.first][node.second] - A[next.first][next.second]);
            if (next.first < 0 || next.first > H - 1
            || next.second < 0 || next.second > W - 1) continue;

            if (danger[next] > max(danger[node], new_danger)) {
                danger[next] = max(danger[node], new_danger);
                visit.push(next);
            }
        }
    }
}

int solve() {
    visited.clear();
    danger.clear();

    cin >> H >> W;
    for(int h=0; h<H; h++) for(int w=0; w<W; w++) {
        cin >> A[h][w];
        visited[{h, w}] = false;
        danger[{h, w}] = INF;
    };

    dijkstra({H-1, W-1});

    return danger[{0, 0}];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> T;
    for(int t=1; t<=T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
}