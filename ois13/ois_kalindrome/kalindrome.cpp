#include <iostream>

using namespace std;

int N, len;
string S;
bool check = false;

bool cmp(string a, string b) {
    if (a.size() != b.size()) return false;

    for (int i = 0; i < a.size(); i++) {
        if (a.at(i) != b.at(i)) return false;
    }

    return true;
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N >> S;

    for(len=1; len<N; len++) {
        bool check = true;
        if (N % len != 0) continue;

        for(int pos=0; pos<=(N/len)/2; pos++) {
            if (!cmp(S.substr(pos*len, len), S.substr(N-len*(pos+1), len))) {
                check = false;
                break;
            }
        }
        
        if (check) break;
    }

    cout << len;

    return 0;
}