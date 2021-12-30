#include <iostream>
#include <vector>
#include <map>
#include <set>

#define MAXN 100000

using namespace std;

struct file {
    bool is_dir, change;
    file(): is_dir(true), change(true) {};
    file(bool i, bool c): is_dir(i), change(c) {};
};

inline bool operator<(const file& left, const file& rigth) {
  return true;
}

ostream &operator<<(ostream &out, file file) {
    return out << "file { " <<  (file.is_dir ? "DIR" : "FILE")
    << ", " << (file.change ? "CHANGE" : "NOT_CHANGE") << " }";
}

int N;
string P;
bool C;
map<string, set<string>> graph;
map<string, file> property;
map<string, bool> status;

vector<string> split(string s) {
    int start = 1, end = s.find("/", 1);
    string path = "";
    vector<string> out;

    out.push_back("/");

    while (end != -1) {
        path += "/" + s.substr(start, end - start);
        out.push_back(path);
        start = end + 1;
        end = s.find("/", start);
    }

    path += "/" + s.substr(start, end - start);
    out.push_back(path);
    return out;
}

/*bool dfs(string path) {
    file file = property[path];
    int count = 0;

    for (string sub_dir : graph[path]) count += dfs(sub_dir);
    if (file.is_dir && count == graph[path].size()) {
        property[path] = {file.name, true, true};
    };

    return property[path].change;
}*/

void stamp(string path) {
    file file = property[path];

    if (file.change) cout << path << endl;
    else for(string next : graph[path]) stamp(next);
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> C >> P;
        status[P] = C;
    };

    property["/"] = {true, true};

    for (auto state : status) {
        vector<string> path = split(state.first);

        property["/"].change = property["/"].change && state.second;

        // If false print and remove

        for(int j=1; j<path.size(); j++) {
            property[path[j]] = {j != path.size() - 1, property[path[j]].change && state.second};
            graph[path[j-1]].insert(path[j]);
        }
    }

    //stamp("/");

    return 0;
}