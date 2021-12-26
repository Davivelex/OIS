#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct missione_t {
    int durata, scadenza;
} missione;

int N, d, s, u = 0;
vector<missione> M;
int memo[366];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> d >> s;
        M.push_back({d, s});
    }

    for (int i=0; i<N; i++) {
        for (int j=M[i].scadenza - M[i].durata; j >= 0; j--) {
            if (memo[j] + 1 > memo[j+M[i].durata]) {
                memo[j + M[i].durata] = memo[j] + 1;
            }
        }
    }
    
    cout << *max_element(memo, memo+366);

    return 0;
}