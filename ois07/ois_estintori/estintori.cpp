#include <iostream>
#include <vector>

#define MAXN 1000

using namespace std;

char map[MAXN][MAXN];
int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int R, C, K = 0;

int search(int i, int j) {
    int e = 0;
    if (map[i][j] == '@') e = 1;
    map[i][j] = '#';
    
    for (auto move : moves) {
        if (map[i+move[0]][j+move[1]] == '.'
            || map[i+move[0]][j+move[1]] == '@') e += search(i+move[0], j+move[1]);
    }

    return e;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> R >> C;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if (map[i][j] == '.') {
                if (search(i, j) == 0) K++;
            }
        }
    }

    cout << K;

    return 0;
}
