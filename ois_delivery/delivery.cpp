#include <iostream>
#include <vector>

using namespace std;

int N, T, R = 0, t;
vector<int> times;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> t;
        times.push_back(t);
    }

    T = times[0];

    for(int i = 1; i < N; i++) {
        if (times[i] + i < T) {
            R++;
            T = times[i] + i;
        }
    }

    cout << T << " " << R;

    return 0;
}