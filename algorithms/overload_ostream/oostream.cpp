#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

// PAIR
ostream &operator<<(ostream &out, const ii &p) {
    return out << "{" << p.first << ", " << p.second << "}";
};

// VECTOR<INT>
ostream &operator<<(ostream &out, const vi &v) {
    out << "[";

    for (int i=0; i<v.size(); i++) {
        out << v[i];
        if (i != v.size()-1) cout << ", ";
    }

    return out << "]";
}

int main() {
    ii p = {123, -654};
    vi v = {1,2,3,4,45,56};

    cout << p << endl << v;

    return 0;
}