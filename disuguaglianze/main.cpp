#include <iostream>

using namespace std;

int N;
string S;

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N >> S;
    int min = 1, max = N;

    for(int i=0; i<N; i++) {
        if(S[i] == '<') {
            cout << min++ << " ";
        } else {
            cout << max-- << " ";
        }
    }
    
    cout << endl;
    return 0;
}