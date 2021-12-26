#include <iostream>
#include <vector>

#define MAXN 101

using namespace std;

int N;
int M[MAXN][MAXN];
int memo[MAXN][MAXN];

int sum(int i, int j) {
    if (i >= N) return 0;
    if (memo[i][j] != -1) return memo[i][j];

    memo[i][j] = M[i][j] + max(sum(i+1, j), sum(i+1, j+1));

    return memo[i][j];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if (j<=i) {
                cin >> M[i][j];
            }

            memo[i][j] = -1;
        }
    }

    cout << sum(0, 0);

    return 0;
}