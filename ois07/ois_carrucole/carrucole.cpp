#include <iostream>
#include <vector>

#define MAXN 10000
#define MAXM 100000

using namespace std;

int N, M, C = 0;
int B[MAXN];
pair<int, int> A[MAXM];

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> B[i];
    }

    for(int i=0; i<M; i++) {
        cin >> A[i].first >> A[i].second;
    }

    for (int i=0; i<M; i++) {
        if (B[A[i].first] + B[A[i].second] == 2) C++;
    }

    cout << C;

    return 0;
}