#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

#define MAXN 100000

using namespace std;

struct tournament {
    int start, end, buyin, prize;
};

int N, M, D, S, E, B, P;
map<int, vector<tournament>> days;
int memo[1000][MAXN+1];

int solve(int D, vector<tournament> T, int i, int s, int m) {
    //cout << T.size() << " " << i << " " << s << " " << m << endl;
    if (i == T.size()) return m;
    if (memo[D][i] != 0) return memo[D][i];

    if (T[i].buyin > m || T[i].start < s) {
        memo[D][i] = solve(D, T, i+1, s, m);
        return memo[D][i];
    };

    memo[D][i] = max(solve(D, T, i+1, s, m), solve(D, T, i+1, T[i].end, m+(T[i].prize-T[i].buyin)));
    return memo[D][i];
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> D >> S >> E >> B >> P;

        days[D].push_back({S, E, B, P});
    }

    for(auto day : days) {
        
        vector<tournament> T = day.second;

        sort(T.begin(), T.end(), [](const tournament &a, const tournament &b) {
            return a.start < b.start;
        });

        M = solve(day.first, T, 0, 0, M);
    }

    cout << M;

    return 0;
}