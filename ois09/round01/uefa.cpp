#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, M, C, D;
string A, B;
map<string, string> countries;
map<string, int> points;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N >> M;

    for(int i=0; i<N ;i++){
        cin >> A >> B;
        countries[A] = B;
    }
    
    for(int i=0; i<M; i++){
        cin >> A >> B >> C >> D;

        if(C == D){
            points[countries[A]] += 2;
            points[countries[B]] += 2;
        } else if(C > D){
            points[countries[A]] += 4;
            points[countries[B]] += 1;
        } else {
            points[countries[B]] += 4;
            points[countries[A]] += 1;
        }
    }

    pair<string,int> finale;
    
    while(points.size()!=0){
        finale.first="";
        finale.second=-1;

        for(auto i : points){
            if(i.second>finale.second){
                finale.second=i.second;
                finale.first=i.first;
            }
        }

        cout << finale.first << " " << finale.second << endl;
        points.erase(finale.first);
    }
    return 0;
}