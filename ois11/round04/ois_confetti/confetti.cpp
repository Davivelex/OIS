#include <iostream>
#include <set>

#define MAXN 100

using namespace std;

int N;
long long C[MAXN], M = INT64_MAX;
set<long long> G;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> C[i];
        M = min(M, C[i]);
    }

    int g = C[0];

    for (int i = 1; i < N; i++) g = gcd(C[i], g);

    for (int i = 1; i * i <= g; i++) if (g % i == 0) {
        G.insert(i);
        if (g / i != i) G.insert(g / i);
    }
 
    for (auto& it : G) cout << it << " ";
}