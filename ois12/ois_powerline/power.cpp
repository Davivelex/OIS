/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>
#include <algorithm>

using namespace std;

// constraints
#define MAXN 100000

// input data
int N, i;
int A[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &A[i]));

    int pos = N-1, val = A[N-1], sol = 0;
    for (i = N-1; i >= 0; i--) {
        if (val <= A[i]) {
            val = A[i];
            pos = i;
        }
        sol = max(sol, pos - i);
    }

    printf("%d\n", sol); // print the result

    return 0;
}
