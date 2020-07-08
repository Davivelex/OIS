#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, i, j, n, R=1;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N;
    vector<int> panini, risultati(N, 1);
    
    for(i=0; i<N; i++) {
        cin >> n;
        panini.push_back(n);
    }

    for(i=N-2; i>=0; i--) {
        for(j=i+1; j<N; j++) {
            if(panini[i] > panini[j] && risultati[i] <= risultati[j]) risultati[i] = risultati[j] + 1;
        }
    }

    cout << *max_element(risultati.begin(), risultati.end()) << endl;

    return 0;
}