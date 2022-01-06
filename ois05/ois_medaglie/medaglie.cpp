#include <algorithm>
#include <iostream>
#include <vector>

#define MAXN 100000

using namespace std;

int N;
int M[MAXN], giorgio[MAXN], gabriele[MAXN];

int max(const int &a, const int &b, const int &c) {
    return (a >= b) ? (a >= c) ? a : c : (b >= c) ? b : c;
}

int dp_giorno(int m);
int dp_gabriele(int m);

int dp_giorgio(int m) {
    int choice_a = (m < N) ? dp_gabriele(m+1)+M[m] : 0;
    int choice_b = (m < N - 1) ? dp_gabriele(m+2)+M[m]+M[m+1] : 0;
    int choice_c = (m < N - 2) ? dp_gabriele(m+3)+M[m]+M[m+1]+M[m+2] : 0;

    return max(choice_a, choice_b, choice_c);
}

int dp_gabriele(int m) {
    int choice_a = (m < N) ? dp_giorgio(m+1)+M[m] : 0;
    int choice_b = (m < N - 1) ? dp_giorgio(m+2)+M[m]+M[m+1] : 0;
    int choice_c = (m < N - 2) ? dp_giorgio(m+3)+M[m]+M[m+1]+M[m+2] : 0;

    int max_choice = max(choice_a, choice_b, choice_c);

    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> M[i];
        M[i] = 500 - 200 * M[i];
    }

    cout << dp_giorgio(0) << endl;
    cout << *max_element(giorgio, giorgio+N);
    
    return 0;
}