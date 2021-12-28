#include <iostream>
#include <vector>

#define MAXN 100001

using namespace std;

int N, finalTime = 0;
int P[MAXN], T[MAXN];
vector<int> M(MAXN, 0);

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N;

    for(int i = 0; i < N; i++) cin >> P[i];
    for(int i = 0; i < N; i++) {
        cin >> T[i];
        finalTime += T[i];
    };
    for(int i = 0; i < N; i++) M[P[i]] = max(M[P[i]], T[i]);
    for (int t : M) finalTime -= t;

    cout << finalTime;

    return 0;
}