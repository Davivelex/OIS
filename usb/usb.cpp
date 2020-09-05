#include <iostream>

using namespace std;

int T, t;
int N, f, c;

int64_t solve() {
    cin >> N >> f >> c;

    int64_t i = 0, t=0, tmax = min(f, c);

    while(true) {
        t += min(f, c);
        i++;
        if(i == N) return min(t, tmax+max(c, f));

        if(t-tmax-max(f, c)>=0) {
            tmax += max(f, c);
            i++;
        }
        if(i == N) return t;
    }
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