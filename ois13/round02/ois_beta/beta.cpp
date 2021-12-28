#include <iostream>
#include <map>

using namespace std;

int N, I;
map<int, int> plays;

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    int first = -1;
    for (int i=0; i<N; i++) {
        cin >> I;
        plays[I]++;

        if (plays[I] > 1) {
            if (first == -1) first = I;
            else if (I != first) {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
}