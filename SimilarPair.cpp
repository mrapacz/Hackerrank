#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int get_root(vector<bool> is_root, int n) {
    for (int i = 1; i <= n; i++) {
        if (is_root[i]) return i;
    }
    return -1;
}

int count_pairs(set<int> S, int s, int T) {
    int l, r;
    l = distance(S.begin(), S.lower_bound(s - T));
    if (S.upper_bound(s + T) == S.end()) r = S.size();
    else r = distance(S.begin(), S.upper_bound(s + T));
    return r - l;
}

void DFS(int s, vector<vector<int> > V, set<int> &S, int T, int &result) {
    for (int i = 0; i < V[s].size(); i++) {
        int current_child = V[s][i];
        set<int> child_set, output_set;

        DFS(current_child, V, child_set, T, result); //update child_set

        set_union(S.begin(), S.end(), child_set.begin(), child_set.end(), inserter(output_set, output_set.begin()));
        S = output_set; //merge sets

        S.insert(current_child);
    }
    result += count_pairs(S, s, T);
}

int main() {
    int n, T;
    cin >> n >> T;
    vector<bool> is_root(n + 1, 1);
    vector<vector<int> > V(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        is_root[b] = false;
        V[a].push_back(b);
    }


    int s = get_root(is_root, n);
    int result = 0;
    set<int> S;
    DFS(s, V, S, T, result);
    cout << result << endl;

    return 0;
}