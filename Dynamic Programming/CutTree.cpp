#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool is_in_set(int node, long long int set) {
    return (((long long int) (1 << (node - 1))) & (set)) != 0;
}

bool BFS(int s, vector<int> G[], long long int set, int n, int k) {
    queue<int> Q;
    bool seen[n + 1];
    for (int i = 0; i < n + 1; i++) seen[i] = false;

    seen[s] = true;
    Q.push(s);
    while (!Q.empty()) {
        int current = Q.front();
        Q.pop();

        for (int i = 0; i < G[current].size(); i++) {
            int next = G[current][i];
            if (!seen[next]) {

                if (is_in_set(next, set)) {
                    Q.push(next);
                    seen[next] = true;
                }
                else {
                    k -= 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (is_in_set(i, set) and !seen[i]) return false;

    return k >= 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> G[n + 1];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    long long int power_set_size = (long long int) (1 << n);
    long long int result = 2; //empty and original set always fit in the criteria

    for (long long int subset = 1; subset < power_set_size - 1; subset++) {
        //cout << "Current subset: " << subset << endl;
        //find root of current T' tree
        bool found = false;
        int root = 1;
        while (!found) {
            if (is_in_set(root, subset)) found = true;
            else root++;
        }
        if (BFS(root, G, subset, n, k)) {
            //cout << "successful " << endl;
            result++;
        }
    }
    cout << result << endl;
    return 0;
}


