#include <iostream>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int A, B, R = 0;
    cin >> A >> B;

    for(int i=A; i <= B; i++) {
        int C = i, P = i;
        int L = 1, K = 1;

        while(C != 1) {
            if (C % 2 == 0) {
                C /= 2;
            } else {
                C *= 3;
                C += 1;
            }
            L++;
        }

        while(P != 1 && K != L) {
            if (P % 2 == 0) {
                P /= 2;
            } else {
                P *= 5;
                P += 1;
            }
            K++;
        }

        if(K<L) R++;
    };

    cout << R << endl;
    return 0;
}