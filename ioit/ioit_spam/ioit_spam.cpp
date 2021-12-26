#include <iostream>
#include <set>

using namespace std;

int B, G, E, N, b = 0, g = 0;
string word;
set< string > bad;
set< string > good;
 
int main(int argc, char** argv) {
	freopen("input.txt", "r", stdin);
	
	cin >> B;
	for(int i=0; i<B; i++) {
		cin >> word;
		bad.insert(word);
	}
	
	cin >> G;
	for(int i=0; i<G; i++) {
		cin >> word;
		good.insert(word);
	}
	
	cin >> E;
	for(int i=0; i<E; i++) { // Al piu' di 1000 iterazioni
		bool is_bad = false;
		bool is_good = false;

		cin >> N;		
		for(int j=0; j<N; j++) { // n iterazioni
			cin >> word;
			if(bad.find(word) != bad.end()) is_bad = true;
			if(good.find(word) != good.end()) is_good = true;
		}
		
		if(is_bad & !is_good) b++;
		if(!is_bad & is_good) g++;
	}
	
	cout << b << " " << g << endl;	
	
	return 0;
}
