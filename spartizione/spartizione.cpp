#include <iostream>

using namespace std;

int P, G, T=0;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> P >> G;

    for(int i=1; P > 0; i++) {
        if(P >= i) {
            T += i;
            P -= i;
        } else {
            T += P;
            P = 0;
        }

        P -= G - 1;
    }

    cout << T << endl;
    return 0;
}