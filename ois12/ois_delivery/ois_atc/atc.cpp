#include <iostream>
#include <vector>

#define MAXN 200
#define INF 10000000

using namespace std;

int N;

int moves[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
char map[MAXN][MAXN];
vector<vector<int>> visited(MAXN, vector<int>(MAXN, INF));

int search(int i, int j, int move, int t) {
    if (i < 0 || j < 0 || i >= N || j >= N
        || visited[i][j] < t || map[i][j] == '#') return INF;
    if (map[i][j] == 'T' && i+j!=0) return t;

    visited[i][j] = t;

    int m = INF;
    for (int next = 0; next<4; next++) {
        if (move == -1) {
            m = min(m, search(i+moves[next][0], j+moves[next][1], next, t));
        } else if (next != move) {
            m = min(m, search(i+moves[next][0], j+moves[next][1], next, t + 1));
        } else {
            m = min(m, search(i+moves[next][0], j+moves[next][1], next, t));
        }
        
    }

    return m;
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }

    int s = search(0, 0, -1, 0);
    if (s != INF) cout << s;
    else cout << -1;

    return 0;
}