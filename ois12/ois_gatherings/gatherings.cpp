#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, D, n, j;
int C = 0;
vector<int> V;

/*int binary_search(int begin, int end, int target) {
    if (begin > end) return -1;

    int avg = (end + begin) / 2;

    if (V[avg] - target < D && V[avg+1] - target >= D) {
        return avg;
    }

    if (V[avg] + D > target) {
        return binary_search(avg + 1, end, target);
    } else return binary_search(begin, avg - 1, target);
}*/

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> N >> D;
    for(int i=0; i<N; i++) {
        cin >> n;
        V.push_back(n);
    }

    sort(V.begin(), V.end());

    for(int i=0; i<N; i++) {
        int K = 0;
        for (j=i+1; j<N; j++) {
            if (V[j] - V[i] >= D) break;
            K++;
        }
        C += K;
        /*if (binary_search(i+1, N-1, V[i]) != -1) {
            C += binary_search(i+1, N-1, V[i])-i+1;
        }*/
    }

    cout << C;

    return 0;
}