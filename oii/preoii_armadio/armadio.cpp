#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int Q, q;
vector<int> V;

void evadi(int Q, vector<int> &N) {
    for(int k=0; k<N.size(); k++) {
        int count = 0;
        for(int i=1; i<N[k]; i++) {
            for(int j=1; j<N[k]; j++) {
                if (i+j+__gcd(i, j) == N[k]) count++;
            }
        }
        N[k] = count;
    }    
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> Q;
    for(int i=0; i<Q; i++) {
        cin >> q;
        V.push_back(q);
    }

    evadi(Q, V);

    cout << V[1];

    return 0;
}