#include <iostream>

#define MAXN 5000

using namespace std;

struct result {
    int prev, count;
};

int N, V[MAXN];

result solve(int i) {
    if (i = 0) return {V[0], 0};

    if (V[i] >= V[i-1] && V[i] % V[i-1] != 0) 
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) cin >> V[i];


    return 0;
}