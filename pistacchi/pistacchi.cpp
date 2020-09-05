#include <iostream>

using namespace std;

int T, N, P, t, i;

float solve() {
    cin >> N >> P;

    int M;
    float K, m;


    for(i=0; i<N; i++) {
        cin >> M >> K;

        if(i==0) {
            m = ((float) P-P/(M+1))*K;
        } else if (((float) P-P/(M+1))*K < m) m = (P-P/(M+1))*K;
    }
    
    return m;
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