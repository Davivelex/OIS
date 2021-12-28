#include <iostream>
#include <vector>

#define MAXN 100002

using namespace std;

int N, P, C = 0;
int H[MAXN];
vector<int> bomb;

bool can_destroy(int tower) {
	return H[tower] > H[tower-1] && H[tower] > H[tower+1];
}

int main() {
	freopen("input.txt", "r", stdin);
	
	cin >> N >> P;

	H[0] = 0;
	H[N+1] = 0;

	for(int i=1; i<=N; i++) {
		cin >> H[i];
	}

	for(int i=1; i<=N; i++) {
		if(can_destroy(i)) bomb.push_back(i);
	}

	for(int p=0; p<P; p++) {
		vector<int> new_bomb;

		for (auto tower : bomb) {
			H[tower] = 0;

			if (tower != 1 && can_destroy(tower-1)) new_bomb.push_back(tower-1);
			if (tower != N && can_destroy(tower+1)) new_bomb.push_back(tower+1);
		}

		C += bomb.size();
		bomb = new_bomb;
	}
	
	cout << C << endl;
	return 0;
}