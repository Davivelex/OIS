#include <iostream>
#include <vector>

using namespace std;

int N, K;
string S;

string max(const string &a, const string &b) {
    return a >= b ? a : b;
}

string solve(string prev, int i, int c) {
    if (c < 0 || i >= S.length()) return prev;
    cout << c << endl;

    S = prev;
    S.erase(prev.begin()+i);

    return max(solve(prev, i+1, c), solve(S, i, c-1));
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N >> K >> S;

    cout << solve(S, 0, K);

    return 0;
}