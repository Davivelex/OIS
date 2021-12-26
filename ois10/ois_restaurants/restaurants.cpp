#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, n, M = -1, V;
vector<vector<int>> ristoranti;

int sum(vector<int> vector) {
    int sum = 1;

    for(int i=0; i<vector.size(); i++) {
        sum += vector[i];
    }

    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N;
    for(int i = 0; i < N; i++) {
        vector<int> ristorante;

        for(int j = 0; j <= N; j++) {
            cin >> n;
            ristorante.push_back(n);
        }

        ristoranti.push_back(ristorante);
    }

    for (int i = 0; i < N; i++) {
        if (sum(ristoranti[i]) > M) {
            M = sum(ristoranti[i]);
            V = i+1;
        }

        cout << V << endl;
    }

    return 0;
}