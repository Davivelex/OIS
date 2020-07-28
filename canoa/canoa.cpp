#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct canottiere_t {
    int forza, peso, indice;
} canottiere;

int N, K, i, f, p;
vector<canottiere> V;

bool compare(canottiere left, canottiere right) {
    if(left.forza -1.5 * left.peso > right.forza - 1.5 * right.peso) return true;

    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N >> K;
    for(i=0; i<N; i++) {
        cin >> f >> p;
        V.push_back({f, p, i+1});
    }

    sort(V.begin(), V.end(), compare);

    for(i=0; i<K; i++) {
        cout << V[i].indice << " ";
    }
    return 0;
}