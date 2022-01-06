#include <iostream>
#include <vector>

#define MAXN 10000

using namespace std;

int N, M;
long long R = 0LL;
string S;
vector<string> V, sent;

int diff(string a, string b) {
    int K = 0;
    for(int i=0; i<min(a.size(), b.size()); i++) {
        if (a.at(i) != b.at(i)) K++;
    }
    return K;
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> S;
        V.push_back(S);
    }

    R += M;
    sent.push_back(V[0]);
    V.erase(V.begin());

    while(sent.size() < N) {
        int min_diff = M+1, posA;
        string bestA = "", bestB = "";

        for(int i=0; i<V.size(); i++) {
            for(int j=0; j<sent.size(); j++) {
                if (diff(V[i], V[j]) < min_diff) {
                    min_diff = diff(V[i], V[j]);
                    bestA = V[i];
                    posA = i;
                    bestB = V[j];
                }
            }
        }

        V.erase(V.begin()+posA);
        sent.push_back(bestA);
        R += min_diff;
    }

    cout << R;

    return 0;
}