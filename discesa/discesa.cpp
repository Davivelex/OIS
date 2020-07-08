#include <iostream>
#include <queue>

using namespace std;

int A, i, j;
priority_queue<int> C;

void discesa(int curx, int cury, int len, int sum, int pyr[10][10]) {
    if(cury > len) C.push(sum);

    discesa(curx, cury+1, len, sum + pyr[cury][curx], pyr);
    discesa(curx+1, cury+1, len, sum + pyr[cury][curx], pyr);
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> A;
    int P[10][10];

    for(i=0; i<A; i++) for(j=0; j<=0; j++) cin >> P[i][j];

    discesa(0, 0, A, 0, P);

    cout << C.top() << endl;

    return 0;
}