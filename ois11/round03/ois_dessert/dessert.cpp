#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

#define MAXN 300000

using namespace std;

class staff {
    public:
    int limit;
    int index;
    vector<staff *> friends;
    vector<staff *> friend_of;
    staff(int l, int i):
        limit(l),
        index(i),
        friends(vector<staff *>()),
        friend_of(vector<staff *>()) {}
};

int N, FN, F, R = 0;
int L[MAXN];
vector<staff *> members;
vector<bool> dessert(MAXN, false);
vector<int> friends_vector;
vector<vector<int>> friends_matrix;
queue<staff *> Q;

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> FN >> L[i];
        members.push_back(new staff(L[i], i));
        
        if (L[i] == 0) Q.push(members[i]);

        friends_vector.clear();
        for(int j=0; j<FN; j++) {
            cin >> F;
            friends_vector.push_back(F);
        }
        friends_matrix.push_back(friends_vector);
    }

    for (int i=0; i<N; i++) {
        for (int other : friends_matrix[i]) {
            members[i]->friends.push_back(members[other]);
            members[other]->friend_of.push_back(members[i]);
        }
    }

    while(!Q.empty()) {
        if (dessert[Q.front()->index]) {
            Q.pop();
            continue;
        }

        staff *member = Q.front();
        Q.pop();

        int count = 0;
        for (staff *other : member->friends) {
            if (dessert[other->index]) count++;
        }

        if (count >= member->limit) {
            dessert[member->index] = true;
            R++;
            for (staff *other : member->friend_of) Q.push(other);
        }
    }

    cout << R;

    return 0;
}