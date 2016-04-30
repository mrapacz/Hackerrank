#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int BFS(int s, vector<int> G[], int n) {
    queue<int> Q;
    Q.push(s);
    int d[101] = {0};
    while (!Q.empty()) {
        int current = Q.front();
        Q.pop();
        for (int i = 0; i < G[current].size(); i++) {
            int next = G[current][i];
            if (d[next] == 0) {
                d[next] = d[current] + 1;
                if (next == n - 1)
                    return d[next];
                Q.push(next);
            }
        }
    }
    return d[n-1];
}

int main() {
    int n;
    cin >> n;
    vector<int> V;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        V.push_back(a);
    }
    vector<int> G[101];
    for (int i = 0; i < n; i++) {
        if (i + 2 < n and !V[i + 2]) G[i].push_back(i + 2);
        if (i + 1 < n and !V[i + 1]) G[i].push_back(i + 1);
    }
    cout << BFS(0, G, n) << endl;
    return 0;
}