#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int N, K;
	cin >> K >> N;
	
	vector <pair<int,int>> guardia(N);
	vector <bool> giorni(K, false);
	for(int i=0; i < N; ++i){
		cin >> guardia[i].first >> guardia[i].second;
	}
	
	int ris = 0, uncovered = 0;
	vector <bool> used(N, false);
	while(uncovered < K){
		int maxi = -1, pos = -1;
		for(int j=0; j < N; ++j){
			if(guardia[j].first <= uncovered && uncovered <= guardia[j].second && !used[j]){
				if(guardia[j].second - uncovered >= maxi){
					maxi = guardia[j].second - uncovered;
					pos = j;
				}
			}
		}
		used[pos] = true;
		uncovered = guardia[pos].second+1;
		++ris;
	}
	
	cout << ris << endl;
	
	return 0;
}