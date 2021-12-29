#include <iostream>

#define MAXN 5000

using namespace std;

int N;
int V[MAXN], len[MAXN], maxLen = 1;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

	cin>>N;
	for(int i=0; i<N; i++) cin>>V[i];

	for(int i=0; i<N; i++){
		len[i]=1;

		for(int j=0; j<i; j++){
			if(V[j] > V[i] || V[i] % V[j] == 0){
				len[i] = max(len[i], len[j]+1);
                maxLen = max(maxLen, len[i]);
			}
		}
	}

	cout << N - maxLen;

	return 0;	
}