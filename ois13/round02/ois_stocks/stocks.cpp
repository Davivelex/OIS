#include <iostream>

#define MAXN 1000001

using namespace std;

int N;
int V[MAXN], S[MAXN];

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) cin >> V[i];
    for(int i=0; i<N; i++) cin >> S[i];

    int totalSum = 0, localSum;
    if (S[0] == 0) localSum = 0;
    else localSum = V[0];

    for(int i=1; i<N; i++) {
        if (S[i] == 0) {
            totalSum = max(totalSum, localSum);
            localSum = 0;
        } else {
            if (V[i] >= V[i-1]) {
                localSum += V[i];
            } else {
                totalSum = max(totalSum, localSum);
                localSum = V[i];
            }
        }
    }

    cout << max(localSum, totalSum);

    return 0;
}