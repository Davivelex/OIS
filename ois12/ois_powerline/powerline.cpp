#include <iostream>
#include <vector>

#define MAXN 100000
using namespace std;

int N, n;
int memo[MAXN];
vector<int> H;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> n;
        H.push_back(n);
    }

    int M = N - 1;
    for(int i=N-1; i>=0; i--) {
        if (H[i] > H[M]) M = i;

        if (H[i] <= H[M]) {
            memo[i] = memo[i+1];
        } else memo[i] = max(M - i, memo[i+1]);
    }

    cout << memo[0];

    return 0;
}