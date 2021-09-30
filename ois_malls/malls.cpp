#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int N, K, dist = -1, mall = 0, n;
vector<int> D;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> n;
        D.push_back(n);
    }

    sort(D.begin(), D.end());

    if (N == 1) {
        if (D[0] > K - D[0]) {
            cout << 0;
        } else cout << K;
    } else {
        for (int i = 1; i < N; i++) {
            if (abs(D[i-1] - D[i])/2 > dist) {
                dist = abs(D[i-1] - D[i])/2;
                mall = D[i-1];
            }
        }

        if (D[0] > dist) {
            cout << 0;
        } else if (abs(K - D[N-1]) > dist) {
            cout << K;
        } else {
            cout << mall + dist;
        }
    }

    return 0;
}