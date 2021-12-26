#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N, h, C=0;
vector<int> H, L;
vector<bool> visited(100000, false);

int search(int h, vector<int> loop) {
    /*cout << h << ": ";
    for (auto x : loop) {
        cout << x << " ";
    }
    cout << endl;
    visited[h] = true;*/
    int i;

    if (find(loop.begin(), loop.end(), h) == loop.end() && !visited[h]) {
        loop.push_back(h);
        return search(H[h], loop);
    } else {
        for(i=0; i<loop.size(); i++) {
            if (loop[i] == h) break;
        }
        return loop.size() - i;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> h;
        H.push_back(h);
    }

    
    for (int i=0; i<N; i++) {
        L.clear();
        if (!visited[i]) {
            C = max(C, search(i, L));
        }
    }

    cout << C << endl;

    return 0;
}
