#include <iostream>
#include <set>
#include <map>

using namespace std;

int N, D, K, R = 0;
map<string, bool> defined;
set<string> primitives;
string S;

int main() {
    freopen("input.txt", "r", stdin);
    
    cin >> N >> D;
    for(int i=0; i<D; i++) {
        cin >> S >> K;

        if (defined[S]) {
            primitives.erase(S);
            R--;
            defined[S] = true;
        }
        
        for(int j=0; j<K; j++) {
            cin >> S;

            if (!defined[S]) {
                defined[S] = true;
                primitives.insert(S);
                R++;
            }
        }
    }

    cout << R << endl;
    for(string primitive : primitives) {
        cout << primitive << endl;
    }

    return 0;
}