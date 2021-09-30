#include <iostream>
#include <vector>

using namespace std;

int N, R = 0, n;
vector<int> P;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N;
    for(int i = 0; i < N; i++) { 
        cin >> n;
        P.push_back(n);
    }

    for(int i = 0; i < N; i++) {
        if (P[i] == 0) {
            if (i > 0 && P[i-1] > 1) {
                P[i]++;
                P[i-1]--;
            } else if (i < N - 1 && P[i+1] > 1) {
                P[i]++;
                P[i+1]--;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if (P[i] == 0) R++;
    }

    cout << R << endl;

    return 0;
}