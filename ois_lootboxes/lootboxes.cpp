#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 5000
#define MAXX 10000

using namespace std;

typedef struct lootbox_t {
    int prob, cost;
} Lootbox;

int N, Q, P=0;
int p, q;
int memo[MAXN][MAXX];
vector<Lootbox> lootboxes;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> p >> q;
        lootboxes.push_back({p, q});
    }

    for (int i = 0; i <= N; i++) {
        for (int c = 0; c <= Q; c++) {
            if (i == 0 || c == 0) {
                memo[i][c] = 0;
                continue;
            }

            if (lootboxes[i-1].cost > c) memo[i][c] = memo[i-1][c];
            else memo[i][c] = max(lootboxes[i-1].prob + memo[i-1][c-lootboxes[i-1].cost], memo[i-1][c]);
        }
    }

    cout << memo[N][Q] << endl;

    return 0;
}