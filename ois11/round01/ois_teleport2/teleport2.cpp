#include <iostream>
#include <math.h>

using namespace std;

int T, N;
double XA, YA, XB, YB, XC, YC, R;

double solve() {
    cin >> XA >> YA >> XB >> YB >> XC >> YC >> R;
    return min(sqrt((XC-XA)*(XC-XA)+(YC-YA)*(YC-YA)) +
    sqrt((XC-XB)*(XC-XB)+(YC-YB)*(YC-YB)-2*R), sqrt((XA-XB)*(XA-XB)+(YA-YB)*(YA-YB)));
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> T;
    for(int t=0; t<T; t++) {
        double result = floor(solve() * 1000000) / 1000000;
        printf("%.6f\n", result);
    }
}