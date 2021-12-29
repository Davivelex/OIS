#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

#define MAXN 1000

using namespace std;

int R, C, K = 0;
int M[MAXN][MAXN];
map<pair<int, int>, bool> seen;
map<int, bool> border;

int moves[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

// usare bfs
void dfs(int i, int j, int k) {
    if (seen[{i, j}]) return;
    if (i < 0 || j < 0 || i > R || j > C) return;
    if (i == 0 || j == 0 || i == R-1 || j == C-1) {
        border[k] = true;
    };

    //cout << "BFS " << i << " " << j << endl;

    seen[{i, j}] = true;

    for (auto move : moves) {
        if(M[i+move[0]][j+move[1]] == 1 && !seen[{i+move[0], j+move[1]}])
            dfs(i+move[0], j+move[1], k);
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> R >> C;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> M[i][j];
            seen[{i, j}] = false;
        }
    }

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            //cout << i << " " << j << endl;
            if (M[i][j] == 1 && !seen[{i, j}]) {
                dfs(i, j, K++);
                seen[{i, j}] = true;
            }
        }
    }

    cout << K - border.size();

    return 0;
}