#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, n;
vector<int> V;
vector<int> memo(99, 1);

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> n;
        V.push_back(n);
    }

    for (int i = N - 1; i >= 0; i--) {
        int m = 0;
        for (int j=i+2; j < N; j++) {
            if (V[j] >= V[i]) m = max(m, memo[j]);
        }
        memo[i] = m + 1;
    }

    cout << *max_element(memo.begin(), memo.end()) << endl;
}