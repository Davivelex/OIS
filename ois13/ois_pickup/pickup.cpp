#include <iostream>
#include <stack>

using namespace std;

int A, B, K, R;
stack<int> ris;

long long pow(int base, int exp) {
    long long p = 1;
    for(int i=0; i<exp; i++) {
        p *= base;
    }

    return p;
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> A >> B >> K;

    for(int i=0; B>0; i++) {
        R = min(B-9, 9) > 0 ? 9 : B;
        ris.push(R);
        B -= R;
    }

    while(!ris.empty()) {
        cout << ris.top();
        ris.pop();
    }

    return 0;
}