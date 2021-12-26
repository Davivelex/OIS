#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, n;
vector<int> V;

float avg(vector<int> V) {
    float sum = 0.0;

    for (int i=0; i<V.size(); i++) {
        sum += V[i];
    }

    return sum / V.size();
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> n;
        V.push_back(n);
    }

    int R = 1000001;
    for (int i=0; i<N; i++) {
        R = min(R, max(abs(V[0]-V[i]), abs(V[N-1]-V[i])));
    }

    cout << R;

    return 0;
}