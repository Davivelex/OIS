#include <iostream>
#include <math.h>

using namespace std;

double N, L, U;

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N >> L >> U;

    if (ceil(N/U) <= floor(N/L)) cout << ceil(N/U);
    else cout << -1;

    return 0;
}