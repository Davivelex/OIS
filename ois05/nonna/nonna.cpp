#include <iostream>
#include <algorithm>

#define MAXN 5001
#define INF 2000000000

using namespace std;

int N, K;
int P[MAXN];
int memo[MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    memo[0] = 0;

    for (int i=0; i<N; i++) {
        if (P[i]+memo[i]<=K) {
            memo[i+1] = P[i] + memo[i];
        } else if (i == N-1) {
            int best = INF;
            for (int j=0; j<N; j++) {
                if (memo[j]+P[i]-K >= 0) best = min(best, memo[j]+P[i]-K);
                if (memo[j]-K >= 0) best = min(best, memo[j]-K);
            }
            memo[i+1] = best + K;
        } else {
            int best = abs(memo[i]+P[i]-K);
            int pos = i;
            for (int j=i-1; j>=0; j--) {
                if (abs(memo[j]+P[i]-K) <= best) {
                    best = abs(memo[j]+P[i]-K);
                    pos = j;
                }
            }
            if (abs(P[i]-K) < best) {
                memo[i+1] = P[i];
            } else memo[i+1] = memo[pos] + P[i];
        }
    }

    if (K == 0) {
        cout << *min_element(P, P+N);
    } else cout << memo[N];

    return 0;
}