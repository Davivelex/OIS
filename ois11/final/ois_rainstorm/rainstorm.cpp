#include <iostream>
#include <vector>

using namespace std;

int M, N, L=100000, i, a, b, r;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> M >> N;
    vector<int> R(N, 0);

    for(i=1; i<M; i++) {
        cin >> a >> b >> r;

        if(r > R[a]) {
            R[a] = r;
            if(r < L) L = r;
        }
    }

    cout << L;
}