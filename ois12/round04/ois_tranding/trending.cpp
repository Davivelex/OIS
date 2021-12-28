#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>

#define MAXN 50000

using namespace std;

int N, T;
vector<string> S(MAXN, "");
map<string, int> c1;
map<int, set<string>> c2(MAXN, vector<string>());

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N >> T;
    for(int i=0; i<N; i++) cin >> S[i];



    int max_string = 0;
    for(int i=0; i<T; i++) {
        c1[S[i]]++;
        c2[c1[S[i]]].push_back(S[i]);
        c2[c1[S[i]]-1].erase(S[i]);
    }

    return 0;
}