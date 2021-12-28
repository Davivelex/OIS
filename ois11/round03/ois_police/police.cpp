#include <iostream>
#include <vector> 

#define MAXN 100001

using namespace std;

int N, K, P = 1, A = 0;
int V[MAXN];
vector<bool> visited(MAXN, false);

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> V[i];

    while(P != K) {
        if (visited[P]) {
            A = -1;
            break;
        } else visited[P] = true;

        P = V[P];
        A++;
    }

    cout << A;

    return 0;
}