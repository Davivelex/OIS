#include <iostream>
#include <map>

using namespace std;

string S;
pair<int, int> pos = {3,1};
long long K = 0;
map<char, pair<int, int>> coo = {{'1',{0,0}},{'2',{0,1}},{'3',{0,2}},{'4',{1,0}},
{'5',{1,1}},{'6',{1,2}},{'7',{2,0}},{'8',{2,1}},{'9',{2,2}},{'0',{3,1}}};

int main() {
    freopen("input.txt", "r", stdin);

    cin >> S;
    for(int i=0; i<S.length(); i++) {
        pair<int, int> new_pos = coo[S.at(i)];
        K += abs(pos.first-new_pos.first)+abs(pos.second-new_pos.second);
        pos = new_pos;
    }

    cout << K + S.length();
}