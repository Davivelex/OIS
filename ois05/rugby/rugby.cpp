#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define MAXN 10000

int N;
int A[MAXN];
int B[MAXN];
vector<vector<int>> graph(MAXN, vector<int>());
set<int> parents;

int team(int n) {
    int sum = 0;

    for (int next : graph[n]) {
        sum += team(next);
    }

    return max(B[n], sum);
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> B[i] >> A[i];
    }

    for(int i=1; i<N; i++) {
        graph[A[i]].push_back(i);
        parents.insert(A[i]);
    }

    cout << team(0);

    return 0;
}