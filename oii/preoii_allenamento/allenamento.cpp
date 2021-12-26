#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, n;
long long C = 0;

long long conta(int N, vector<int> A) {
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            int index_min = min_element(A.begin()+i, A.begin()+j+1)-(A.begin()+i);
            int index_max = max_element(A.begin()+i, A.begin()+j+1)-(A.begin()+i);

            if (index_max > index_min) C++;
        }
    }

    return C;
};

int main() {
    cin.exceptions(istream::failbit);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int& i : A) {
        cin >> i;
    }

    cout << conta(N, A);

    cout << endl;

    return 0;
}