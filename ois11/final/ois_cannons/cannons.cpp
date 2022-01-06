#include <iostream>
#include <vector>
#include <queue>

#define INF INT32_MAX
#define MAXN 1000000

using namespace std;

int N;
int T[MAXN];
vector<int> distances(MAXN, INF);

struct order {
    bool operator()(const int &left, const int &right) {
        return distances[left] > distances[right];
    }
};

priority_queue<int, vector<int>, order> visit;

void dijkstra(int start) {
    visit.push(start);
    distances[start] = 0;

    while(!visit.empty()) {
        int cannon = visit.top();
        visit.pop();

        // The new distance from the neighbor is the same as the
        // current because the weight of the pre-existing arc is 0
        if (distances[T[cannon]] > distances[cannon]) {
            distances[T[cannon]] = distances[cannon];
            visit.push(T[cannon]);
        }

        // Visit the prev with a cost of 1
        if (distances[cannon - 1] > distances[cannon] + 1) {
            distances[cannon - 1] = distances[cannon] + 1;
            visit.push(cannon - 1);
        }

        // Visit the next with a cost of 1
        if (distances[cannon + 1] > distances[cannon] + 1) {
            distances[cannon + 1] = distances[cannon] + 1;
            visit.push(cannon + 1);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> T[i];
    }

    dijkstra(0);
    cout << distances[N - 1];

    return 0;
}