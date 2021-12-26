#include <iostream>
#include <vector>

using namespace std;

int N;
long n, m;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> n >> m;

        if (n > 0 && m > 0) {
            cout << "+" << endl;
        } else if (n < 0 && m < 0) {
            if ((m - n) % 2 == 0) {
                cout << "-" << endl;
            } else cout << "+" << endl;
        } else if (n*m <= 0) {
            cout << "0" << endl;
        }
    }

    return 0;
}