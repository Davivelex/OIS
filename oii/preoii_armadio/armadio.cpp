#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int Q, q;
vector<int> V;

void evadi(int Q, vector<int> &N) {
    for(int k=0; k<N.size(); k++) {
        int count = 0;
        for(int i=1; i<(Q-1)/2; i++) {
            for(int j=1; j<(Q-1)/2; j++) {
                if (i+j+__gcd(i, j) == Q) count++;
            }
        }
        N[k] = count*2;
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

    return 0;
}