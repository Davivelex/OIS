#include <iostream>
#include <vector>

#define MAXN 10000
#define MAXM 100000

using namespace std;

int N, M;
int monete[MAXN], A[MAXM], B[MAXM];

// consegna
vector<bool> visto(MAXN, false);
vector<vector<int>> grafo(MAXN, vector<int>());

int dfs(int nodo) {
    if (visto[nodo]) return 0;
    visto[nodo] = true;

    int sotto = 0;

    for (int succ : grafo[nodo]) {
        sotto += dfs(succ);
    }

    return sotto + monete[nodo];
}

int raccogli(int N, int M, int monete[], int A[], int B[]) {
    for (int i = 0; i<M; i++) {
        grafo[A[i]].push_back(B[i]);
        grafo[B[i]].push_back(A[i]);
    }

    return dfs(0);
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> monete[i];
    for(int i=0; i<M; i++) cin >> A[i] >> B[i];

    cout << raccogli(N, M, monete, A, B);

    return 0;
}