#include <iostream>
#include <vector>

using namespace std;

int N;
long long A, B;

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> A >> B;

        if (A*B <= 0) cout << 0;
        else {
            if (A > 0 && B > 0) cout << "+";
            else {
                if ((abs(A)-abs(B))%2==0) cout << "-";
                else cout << "+";
            }
        }
    }

    return 0;
}