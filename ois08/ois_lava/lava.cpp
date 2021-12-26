#include <iostream>
#include <map>

#define MAXN 1000
#define INF 10000000

using namespace std;

map<pair<int, int>, int> seen;
int H, W;
char c;
int M[MAXN][MAXN];

int moves[5][2] = {{1, 0}, {1, 1}, {1, 0}, {0, 2}, {2, 0}};

int bfs(int i, int j, int k) {
    if (seen[{i, j}]) return seen[{i, j}];
    if (i == H - 1 && j == W - 1) return k;

    //cout << i << " " << j << endl;

    int m = INF;
    for (auto move : moves) {
        if (M[i+move[0]][j+move[1]] == 1)
            m = min(m, bfs(i+move[0], j+move[1], ++k));
    }

    seen[{i, j}] = m;
    return k;
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> H >> W;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >> c;
            if (c == '.') M[i][j] = 1;
            else M[i][j] = 0;

            seen[{i, j}] = INF;
        }
    }

    cout << bfs(0, 0, 0) << endl;

    for (auto x : seen) {
        cout << x.first.first << ", " << x.first.second << " -> " << x.second << endl;
    }
}