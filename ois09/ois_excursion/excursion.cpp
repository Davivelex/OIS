#include <iostream>
#include <vector>

using namespace std;

#define MAX 2000
#define INF 10000000

int H, W;
int map[MAX][MAX];
int moves[4][2] = {{1, 0}, {-1, 0}, {1, 0}, {-1, 0}};
vector<vector<int>> visited(MAX, vector<int>(MAX, 0));

int search(int i, int j, int dir, int c) {
    cout << i << " " << j << endl;
    if (visited[i][j] != 0) return c + visited[i][j];

    visited[i][j] = c;

    int move = 0;
    int diff = INF;
    for (int k=0; k<4; k++) {
        if (k+dir == 3 || i+moves[k][0] < 0 || j+moves[k][1] < 0 || i+moves[k][0] >= H || j+moves[k][1] >= W) continue;

        if (abs(map[i][j] - map[i+moves[k][0]][j+moves[k][1]]) < diff) {
            diff = abs(map[i][j] - map[i+moves[k][0]][j+moves[k][1]]);
            move = k;
        } else if (abs(map[i][j] - map[i+moves[k][0]][j+moves[k][1]]) == diff) {
            if (map[i+moves[k][0]][j+moves[k][1]] < map[i+moves[move][0]][j+moves[move][1]]) {
                move = k;
            }
        }
    }

    return search(i+moves[move][0], j+moves[move][1], move, c+1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> H >> W;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >> map[H][W];
        }
    }

    cout << search(0, 0, -1, 0);

    return 0;
}