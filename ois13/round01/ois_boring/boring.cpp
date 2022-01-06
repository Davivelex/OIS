#include <iostream>
#include <vector>

#define MOD 1000000007
#define MAXN 100000

using namespace std;

struct number {
    int quo, rem;
    number(int n): quo(n/MOD), rem(n%MOD) {}
    void operator*=(const number& other) {
        quo = MOD * quo * other.quo + quo * other.rem + rem 
        * other.quo + (rem * other.rem) / MOD;
        rem = (rem * other.rem) % MOD;
    }
    void operator^=(const int& exp) {
        number result = {1};
        for(int i=0; i<exp; i++) {
            result *= *this;
        }
        quo = result.quo;
        rem = result.rem;
    }
};

int N, Q, X, Y, B, C, K;
vector<number> V;

bool operator<(const number& lhs, const number& rhs) {
    if (lhs.quo == rhs.quo) {
        return lhs.rem < rhs.rem;
    } else return lhs.quo < rhs.quo;
}

/*number pow(int base, int exp) {
    number result = {0, 1};
    for(int i=0; i<exp; i++) {
        result = result * result;
    }
    return result;
}*/

int main() {
    freopen("input.txt", "r", stdin);

    /*cin >> N;
    for(int i=0; i<N; i++) {
        cin >> X;
        V.push_back({0, X});
    }
    
    cin >> Q;
    for(int i=0; i<Q; i++) {
        cin >> K;
        if (K == 1) {
            cin >> X;
            cout << V[X].rem << endl;
        } else {
            cin >> X >> Y >> B >> C;
            for(int i=X; i<=Y; i++) {
                if (V[i] < B*pow(i, C)) V[i] = B*pow(i, C);
                cout << V[i].rem << endl;
            }
        }
    }*/

    number one = {MOD-1};
    number two = {10};
    two ^= 2;
    one *= two;
    cout << one.quo << " " << one.rem << endl;
    return 0;
}