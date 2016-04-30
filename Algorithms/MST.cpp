#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
struct edge {
    int s;
    int e;
    int w;
};

bool operator<(edge a, edge b) {
    return a.w > b.w;
}

void MST(vector<edge> G[], vector<edge> H[], int s, bool seen[], int n) {
    int count_seen = 1;
    priority_queue<edge> edges;
    seen[s] = true;
    for (int i = 0; i < G[s].size(); i++) {
        edges.push(G[s][i]);
    }

    while (count_seen < n) {
        edge current = edges.top();
        int next = current.e;
        edges.pop();

        if (seen[next]) continue;
        seen[next] = true;
        for (int i = 0; i < G[next].size(); i++) {
            edges.push(G[next][i]);
        }
        H[current.s].push_back(current);
        swap(current.s, current.e);
        H[current.s].push_back(current);

        count_seen++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<edge> G[3001];
    for (int i = 0; i < m; i++) {
        edge e;
        cin >> e.s >> e.e >> e.w;
        G[e.s].push_back(e);
        swap(e.e, e.s);
        G[e.s].push_back(e);

    }
    int s;
    cin >> s;

    vector<edge> H[3001];
    bool seen[3001] = {false};
    MST(G, H, s, seen, n);
    return 0;
}