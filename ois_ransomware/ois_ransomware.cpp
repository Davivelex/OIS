#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N;
string input;
vector<string> numbers;
unordered_map<string, int> codes;

int main(int argc, char** argv) {
	freopen("input.txt", "r", stdin);
	
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> input;
		numbers.push_back(input);
	}
	
	for(int i=0; i<10; i++) {
		cin >> input;
		codes[input] = i;
	}
	
	for(auto number : numbers) { // Al piu' di 100 iterazioni
		int p = 0, i = 0;
		
		while(p + i < number.length()) { // n iterazioni
			string code = number.substr(p, ++i);
			if(codes.find(code) != codes.end()) {
				cout << codes[code];
				p += i;
				i = 0;
			}
		}
		cout << endl;
	}
}
