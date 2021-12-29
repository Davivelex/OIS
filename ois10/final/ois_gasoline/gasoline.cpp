#include <assert.h>
#include <stdio.h>
#include <vector>
#include <iostream>

#define MAXN 1000000
 
using namespace std;
 
int N;
long long total = 0LL;
int P[MAXN], G[MAXN];
 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    assert(1 == scanf("%d", &N));
    for (int i = 0; i < N; i++) assert(1 == scanf("%d", &P[i]));
    for (int i = 0; i < N; i++) assert(1 == scanf("%d", &G[i]));
 
    for(int i=0; i<N; i++) if(P[i] <= P[i+1]) P[i+1]=P[i];
    for(int i=0; i<N; i++) total += (G[i]*P[i]);

    cout << total;

    return 0;
}