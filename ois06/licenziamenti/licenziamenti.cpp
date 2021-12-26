#include <iostream>
#include <vector>

#define MAXN 100000

using namespace std;

int N;
int B[MAXN];
int C[MAXN];
vector<vector<int>> graph(MAXN, vector<int>());

int dfs(int n, int m) {
    int l = 0;
    if (B[n] > m) l++;

    for (int next : graph[n]) {
        l += dfs(next, min(B[n], m));
    }

    return l;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> B[i] >> C[i];
    }

    for(int i=1; i<N; i++) {
        graph[C[i]].push_back(i);
    }

    cout << dfs(0, B[0]);

    return 0;
}