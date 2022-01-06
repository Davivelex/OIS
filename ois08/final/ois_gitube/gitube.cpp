#include <iostream>
#include <vector>

using namespace std;

int D, N, C;
vector<vector<int>> count(53, vector<int>(7, -1));

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> D >> N;
    
    for(int i=0; i<=D; i++) {
        count[(i-1)/7][(i-1)%7] = 0;
    }

    for(int i=0; i<N; i++) {
        cin >> C;
        count[(C-1)/7][(C-1)%7]++;
    }

    for(int g = 0; g < 7; g++) {
        for(int s = 0; s < 53; s++) {
            if (count[s][g] == -1) continue;

            if (count[s][g] < 10) {
                cout << ".";
            } else if(count[s][g] >= 10 && count[s][g] < 19) {
                cout << "o";
            } else cout << "O";
        }
        cout << endl;
    }
}