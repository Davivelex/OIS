#include <iostream>
#include <vector>

using namespace std;

int N, P, C = 0, h;
vector<int> H;

int main(int argc, char** argv) {
	freopen("input.txt", "r", stdin);
	
	cin >> N >> P;
	
	for(int i=0; i<N; i++) {
		cin >> h;
		H.push_back(h);
	}
	
	for(int p=0; p<P; p++) {
		int k = C;
		for(int i=0; i<N; i++) {
			if(i == 0 && H[i] != 0 && H[i] > H[i+1]) {
				H[0] = 0;
				C++;
				i++;
			} else if(H[i] != 0 && H[i] > H[i-1] && H[i] > H[i+1]) {
				H[i] = 0;	
				C++;
				i++;
			} else if(i == N - 1 && H[i] != 0 && H[i] > H[i-1]) {
				H[N-1] = 0;
				C++;
				i++;
			}
		}
		if(k == C) break;
	}
	
	cout << C << endl;
	return 0;
}