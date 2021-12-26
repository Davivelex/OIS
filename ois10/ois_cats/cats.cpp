#include <iostream>
#include <vector>

#define MAXN 1001

using namespace std;

int NM, NF, c;
int memo[MAXN][MAXN], M[MAXN], F[MAXN];

int main() {
    freopen("input.txt", "r", stdin);

    cin >> NM >> NF;
    for(int i=1; i<=NM; i++) cin >> M[i];
    for(int i=1; i<=NF; i++) cin >> F[i];

    for(int i=0; i<=NM; i++) {
        for(int j=0; j<=NF; j++) {
            if (i == 0 || j == 0) memo[i][j] = 0;
            else memo[i][j] = max(
                memo[i-1][j-1]+abs(M[i]-F[j]), 
                max(
                    memo[i][j-1],
                    memo[i-1][j]
                )
            );
        }
    }

    cout << memo[NM][NF] << endl;

    return 0;
}