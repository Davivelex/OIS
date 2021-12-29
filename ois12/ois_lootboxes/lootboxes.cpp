#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 5001
#define MAXX 10001

using namespace std;

typedef struct lootbox_t {
    int prob, cost;
} lootbox;

int N, Q, P=0;
int p, q;
vector<int> prec(MAXX, 0), memo(MAXX, 0);
vector<lootbox> lootboxes;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> p >> q;
        lootboxes.push_back({p, q});
    }

    for (int i = 1; i <= N; i++) {
        for (int c = 0; c <= Q; c++) {
            if (c == 0) {
                memo[c] = 0;
                continue;
            }

            if (lootboxes[i-1].cost > c) memo[c] = prec[c];
            else memo[c] = max(lootboxes[i-1].prob + prec[c-lootboxes[i-1].cost], prec[c]);
        }
        prec = memo;
    }

    cout << memo[Q] << endl;

    return 0;
}