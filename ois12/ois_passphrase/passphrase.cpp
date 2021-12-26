#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
string parola;

bool cmp(string a, string b) {
    for(int i=0; i<min(a.size(), b.size()); i++) {
        if (a[i] != b[i]) return false;
    }

    return true;
}

string solve(string parola, int K) {
	string parola_giusta = parola, parola_da_salvare = parola;

	while(K>0) {
		for(int i = 0; i<parola_da_salvare.length() - 1; i++) {
			parola = parola_da_salvare;
			parola.replace(i, 1, "");

			if (!cmp(parola, parola_giusta) && parola > parola_giusta) {
				parola_giusta = parola;
			} else {
                parola_giusta = parola;
            }
		}

		parola_da_salvare = parola_giusta;
        K -= 1;
	}

	return parola_da_salvare;
}

int main() {
    freopen("input.txt", "r", stdin);

	cin >> N >> K >> parola;

	cout << solve(parola, K) << endl;
    return 0;
}