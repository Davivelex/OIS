#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, i, a, b;
vector<int> A;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> N >> M;
    for(i=0; i<N; i++) {
        cin >> a;
        A.push_back(a);
    }
    for(i=0; i<M; i++) {
        cin >> a >> b;
        iter_swap(find(A.begin(), A.end(), a), find(A.begin(), A.end(), b));
    }

    cout << *A.begin() << endl;
    return 0;
}