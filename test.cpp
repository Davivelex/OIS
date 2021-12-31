#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> V;

void func() {
    for(int i=0; i<V.size(); i++) {
        if (V[i]%2 != 0) {
            V[i] = V[i]*2;
        }
    }
}

int main() {
    V = {1, 2, 3, 4, 5, 6, 7, 8};

    func();

    for(auto x : V) {
        cout << x << " ";
    }

    return 0;
}
