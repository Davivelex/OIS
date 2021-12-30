#include <iostream>
#include <algorithm>

#define MAXN 5000
#define MAXK 5000
#define INF 1000000000

using namespace std;

int N, K;
int P[MAXN];
int memo[MAXN + 1][MAXK + 1];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> N >> K;

    for (int i = 0; i < N; i++) cin >> P[i];

    for(int i=1; i<=K; i++) memo[0][i] = INF;

    for(int i=1; i<=N; i++) {
        for(int j=0; j<=K; j++) {
            memo[i][j] = memo[i-1][j];

            if(P[i - 1] <= j) {
                memo[i][j] = min(memo[i][j], memo[i-1][j - P[i - 1]]+ P[i -1]);
            } else {
                memo[i][j] = min(memo[i][j], P[i - 1]);
            }
        }
    }

    cout << memo[N][K] << endl;

    return 0;
}