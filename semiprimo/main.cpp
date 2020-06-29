#include <iostream>
#include <math.h>

using namespace std;

int N;
int P, P1, P2;
 
bool primo(long x) {
	
	for(long i = 2; i <= sqrt(x); i++)
	    if(x % i == 0) {
	    	P = i;
	        return false;
	    }

	return true;        
}
 
int main() {    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	 
	cin >> N;		
	
    if(primo(N))			
	    cout << -1;
    else {
    	P1 = P;
    	P2 = N / P;

        if(primo(P1) && primo(P2)) cout << P1 << " " << P2 << endl;
        else cout << -1 << endl;
    }
    return 0;
}