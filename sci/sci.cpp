#include <iostream>
#include <vector>

using namespace std;

int T, t;
int N, i, h;


int solve() {
    vector<int> H = vector<int>();
    int delta = 0, bottom = 0, top = 0;

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> h;
        H.push_back(h);
    }

    for(i=1; i<N; i++) {
        if(H[bottom] > H[i]) bottom = i;
        if(H[top] < H[i]) {
            top = i;
            bottom = i;
        }   

        if(H[top] - H[bottom] > delta) delta = H[top] - H[bottom];
    }

    return delta;
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