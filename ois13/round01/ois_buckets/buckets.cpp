#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, n;
vector<int> V;

int main() {
    
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> n;
        V.push_back(n);
    }

    sort(V.begin(), V.end());

    for(int i=0; i<N-1; i++) {
        if (V[i] == V[i+1]) {
            cout << "Impossible";
            return 0;
        }
    }

    cout << "Ok";

    return 0;
}