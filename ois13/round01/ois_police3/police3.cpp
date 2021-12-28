#include <iostream>
#include <vector>

using namespace std;

int N, n;
vector<int> V;

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> n;
        V.push_back(n);
    }

    int inc = V[0];
    int exc = 0;

    for(int i=1; i<N; i++) {
        int ninc = V[i] + min(inc, exc);
        int nexc = inc;

        inc = ninc;
        exc = nexc;
    }

    cout << min(inc, exc);
}