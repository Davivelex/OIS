#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int N1, N2, n;
int C = 0;
vector<int> V1, V2;

bool binary_search(int begin, int end, int target) {
    int avg = (end + begin) / 2;

    if (V1[avg] == target) return true;
    if (begin > end) return false;

    if (V1[avg] < target) {
        return binary_search(avg + 1, end, target);
    } else return binary_search(begin, avg - 1, target);
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N1 >> N2;
    for(int i = 0; i < N1; i++) {
        cin >> n;
        V1.push_back(n);
    }

    for(int i = 0; i < N2; i++) {
        cin >> n;
        V2.push_back(n);
    }

    sort(V1.begin(), V1.end());

    for(int i=0; i<N2; i++) {
        if (binary_search(0, N1-1, V2[i])) C++;
    }

    cout << C;

    return 0;
}