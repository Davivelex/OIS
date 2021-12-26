#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 10000

using namespace std;

int N, p;
vector <int> P;
int memo[MAXN];

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> p;
        P.push_back(p);
    }

    for(int i=0; i<N; i++) {
        int m = 0;
        for(int j=0; j<i; j++) {
            if (P[j] >= P[i]) m = max(m, memo[j]);
        }

        memo[i] = m + 1;
    }

    cout << *max_element(memo, memo+N);

    return 0;
}