#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 100000

using namespace std;

class rope {
    public:
    int time;
    vector<rope *> ropes;
    rope(int time): time(time),ropes(vector<rope *>()){}
} *current, *best;

int N, finalTime = 0;
int T[MAXN], P[MAXN];
vector<rope *> ropes;

rope * maxTime(rope *first, rope * second) {
    if (first->time > second->time) return first;
    else if (first->time == second->time) {
        return first->ropes.size() >= second->ropes.size() ? second : first;
    }
    else return second;
}

int main() {
    freopen("input.txt", "r", stdin);

    rope *handle = new rope(0);
    ropes.push_back(handle);

    cin >> N;
    for(int i=0; i<N; i++) cin >> P[i];
    for(int i=0; i<N; i++) cin >> T[i];
    for(int i=0; i<N; i++) ropes.push_back(new rope(T[i]));
    for(int i=0; i<N; i++) ropes[P[i]]->ropes.push_back(ropes[i+1]);

    ropes = handle->ropes;
    while(ropes.size() != 1 || !ropes[0]->ropes.empty()) {
        best = ropes[0];
        for (rope *rope: ropes) {
            best = maxTime(best, rope);
        }
        for (rope *rope: ropes) {
            if (rope != best) {
                best->ropes.push_back(rope);
                finalTime += rope->time;
            }
        }

        ropes = best->ropes;
    }

    cout << finalTime;

    return 0;
}