#include <iostream>
#include <vector>

using namespace std;

int fib(int n) {
    int i;
    vector<int> fib;

    fib.push_back(1);
    fib.push_back(1);

    for(i=2; i<n; i++) {
        fib.push_back(fib[i-2] + fib[i-1]);
    }

    return fib[i-1];
}

string solve(int n) {
    int k=1;
    string lwf;
    while(fib(k) < n) k++;

    if (n == 1) return "1";

    for(int i=k-1; i > 0; --i) {
        if (fib(i) <= n && i != 2) {
            lwf.insert(lwf.begin(), '1');
            n -= fib(i);
        } else {
            lwf.insert(lwf.begin(), '0');
        }
    }

    return lwf;
}

int N;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N;
    cout << solve(N);
    return 0;
}
