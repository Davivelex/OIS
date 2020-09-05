#include <iostream>

using namespace std;

int T, t;
string S;

int solve() {
    cin >> S;

    int max = 0, i, j, R=1;

    for(i=S.length(); i>=0; i--) {
        string sub = S.substr(i, S.length());
        cout << sub << endl;
        int C = 1, max = sub[0];
        for(j=1; j<sub.length(); j++) {
            if(sub[i] > sub[max]) {
                max = i;
                C++;
            }
        }
        cout << C;
        if(C > R) R = C;
    }

    return R;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> T;
    for(t=1; t<=T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}