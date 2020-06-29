#include <iostream>

using namespace std;

int N, C = 0;

int collatz(int n) {
    C++;
    if(n == 1) {
        return C;
    } else if (n % 2 == 0) {
        return collatz(n / 2);
    } else {
        return collatz(n * 3 + 1);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N;
    cout << collatz(N) << endl;
    return 0;
}