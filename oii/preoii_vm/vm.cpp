#include <iostream>
#include <vector>

#define MAXN (int)2e5

using namespace std;

long long aggiorna(int N, vector<int> A, vector<int> B) {
    long long aggiornamentiTotali = 0LL;
    
    for (int i=A.size()-2; i>=0; i--) {
        long long aggiornamenti = (A[i+1]-A[i])/B[i];
  
        A[i] += aggiornamenti * B[i]; 

        aggiornamentiTotali += aggiornamenti;
    }

    return aggiornamentiTotali;
}

int N, n;
vector<int> A, B;

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> n;
        A.push_back(n);
    };
    for(int i=0; i<N; i++) {
        cin >> n;
        B.push_back(n);
    }

    cout << aggiorna(N, A, B);

    cout << endl;

    return 0;
}
