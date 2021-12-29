#include <iostream>

using namespace std;

#define MAXN 100000

long long N, D, count, diff;
long long P[MAXN];

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N >> D;
    for(int i=0; i<N; i++) cin >> P[i];
    
    for(int left = 0, right = 1; left <= N-2;){
        diff = P[right] - P[left];
        if(diff >= D || right >= N){
            count += (right-left-1);
            left++;	
        } else right++;
    }
    
    cout << count;

    return 0;
}