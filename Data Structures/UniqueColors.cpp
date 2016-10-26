#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

void printVector(vector<int> V) {
    for (int i = 0; i < V.size(); i++)
        cout << V[i] << " ";
    cout << endl;
}

int BFS(int s, int d, map<pair<int, int>, int> &M, vector<int> V[], int n, int color[]) {
    int parent[n + 1];
    for (int i = 0; i < n + 1; i++) {
        parent[i] = 0;
    }

    pair<int, int> a;
    a.first = d;
    a.second = s;
    if (M.find(a) != M.end()) return M[a];

    queue<int> Q;
    bool found = false;
    Q.push(s);
    while (!Q.empty() and !found) {
        int current = Q.front();
        Q.pop();
        for (unsigned int i = 0; i < V[current].size(); i++) {
            int next = V[current][i];
            if (parent[current] != next) {
                Q.push(next);
                parent[next] = current;
            }
            if (next == d) found = true;
        }
    }
    int i = d;
    set<int> S;
    while (d != 0) {
        S.insert(color[d]);
        d = parent[d];
    }
    int sum = S.size();
    swap(a.first, a.second);
    M[a] = sum;

    return sum;
}

int main() {

    int n;
    cin >> n;
    vector<int> V[n+1];
    map<pair<int, int>, int> M;
    int color[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    //solution
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += BFS(i, j, M, V, n, color);
        }
        cout << sum << endl;
    }
    return 0;
}