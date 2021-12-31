#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int N, R, A, B;
vector<ii> S;


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N >> R;
    for(int i=0; i<N; i++) {
        cin >> A >> B;
        S.push_back({A, B});
    }

    sort(S.begin(), S.end(), [](const ii &lhs, const ii &rhs) {
        return lhs.second < rhs.second;
    });

    int free_pos = 1;
    int days = 0;

    for(int i=0; i<N; i++) {
        days += abs(S[i].second - free_pos++);
        days += abs(S[i].first - R);
    }

    cout << days;

    return 0;
}