#include <iostream>
#include <set>

#define MAXN 100
#define INF 2000000000

using namespace std;

int N, B;
int V[MAXN];
set<int> combi, nuovi;


int main() {
    freopen("input.txt", "r", stdin);

    cin >> N >> B;
    for(int i=0; i<N; i++) {
        cin >> V[i];
    }

    for(int i=0; i<N; i++) {
        nuovi.clear();
        for(auto combo : combi) {
            nuovi.insert(combo + V[i]);
        }

        for(auto nuovo : nuovi) {
            combi.insert(nuovo);
        }

        combi.insert(V[i]);
    }

    int best = INF;
    int max = 0;
    for (auto combo : combi) {
        if (combo >= B && combo <= best) best = combo;
        else if (combo > max) max = combo;
    }

    cout << ((max < B) ? max : best) << endl;
    return 0;
}