#include <iostream>
#include <vector>
#include <map>

#define MAXN 100000

using namespace std;

typedef map<int, int> colors;

class node {
    public:
    int color;
    int index;
    vector<node *> nodes;
    node(int color, int index): color(color),index(index),nodes(vector<node *>()){};
} *tree;

int N, K = 0, R = 0;
int C[MAXN], P[MAXN];
vector<node *> balls;
vector<bool> visited = vector<bool>(MAXN, false);

colors sum(colors first, colors second) {
    for (auto color : second) {
        first[color.first] = first[color.first] + color.second;
    }
    return first;
}

int most_frequent(colors col) {
    int K = 0, C=0;
    for (auto x : col) {
        K = max(K, x.second);
    }
    for (auto x : col) {
        if (x.second == K) C++;
    }
    return C;
}

colors new_colors() {
    colors result;
    for (int i=0; i<K; i++) {
        result[i] = 0;
    }
    return result;
}

// DEBUG FUNCTION
void stamp(colors col) {
    for(auto x : col) {
        cout << x.second << " ";
    }
    cout << endl;
}

colors dfs(node *node) {
    colors col = new_colors();
    
    cout << node->index << "(" << node->color << ") ";    

    if (visited[node->index]) return col;
    visited[node->index] = true;

    for (auto ball : node->nodes) {
        col = sum(col, dfs(ball));
    }

    col[node->color]++;
    R = max(R, most_frequent(col));

    // DEBUG
    cout << node->index << " => ";
    stamp(col);

    return col;
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> C[i];
        K = max(K, C[i]);
    };
    for(int i=0; i<N-1; i++) cin >> P[i];
    for(int i=0; i<N; i++) balls.push_back(new node(C[i], i));
    for(int i=0; i<N-1; i++) balls[P[i]]->nodes.push_back(balls[i+1]);

    dfs(balls[0]);
    cout << R;
}