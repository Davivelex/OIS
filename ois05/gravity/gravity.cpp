#include <iostream>

#define MAXN 10000

using namespace std;

int N, V[MAXN];
int memo[MAXN+1];

int solve(int i, int c, int d, int prev) {
    if (i == 0) return 0;
    if (i == N) return 0;
    if (memo[i] != 0) return memo[i];

    if ((V[i] - V[prev])*d > 0) {
        memo[i] = solve(i+1, c, d, i);
        return memo[i];
    }
    
    memo[i] = max(solve(i+1, c, d, i), solve(i+1, (V[i] - V[prev])*d > 0 ? c+1 : 1, V[i] - V[prev], i)+1);
    return memo[i];
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &V[i]);

    cout << solve(1, 1, 0, 0)+1;
}