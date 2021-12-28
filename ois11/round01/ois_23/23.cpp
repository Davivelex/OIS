#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define MAXN 100000000

using namespace std;

int sum_in_base(int number, int base) {
    int sum = 0;

    while(number > 0) {
        sum += number % base;
        number /= base;
    }

    return sum;
}

int N, t, c = 0;
vector<int> T;
int table[MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> t;
        T.push_back(t);
    }

    for(int i = 1; i <= *max_element(T.begin(), T.end()); i++) {
        if (__builtin_popcount(i) == sum_in_base(i, 3)) table[i] = ++c;
        else table[i] = c;
    }

    for (int n : T) {
        cout << table[n] << " ";
    }

    return 0;
}