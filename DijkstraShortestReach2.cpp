//
// Created by maciej on 07.04.16.
//

//
// Created by maciej on 06.04.16.
//
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <map>

using namespace std;
struct edge {
    int b;
    int w;
};
struct vec {
    int n;
    int dist;
};

bool operator<(vec a, vec b) {
    return a.dist <= b.dist;
}

void dijkstra(vector<edge> V[], int T[], int s, int n) {

    T[s] = 0;
    priority_queue<vec> Q;
    vec current;

    current.n = s;
    current.dist = 0;

    Q.push(current);

    while (!Q.empty()) {
        current = Q.top();
        Q.pop();
        for (int i = 0; i < V[current.n].size(); i++) {
            int next = V[current.n][i].b;
            int weight = V[current.n][i].w;

            if (T[next] == -1 or T[current.n] + weight < T[next]) {

                T[next] = T[current.n] + weight;
                vec x;
                x.n = next;
                x.dist = T[next];
                Q.push(x);
            }
        }
    }
}

void add_edge(vector<edge> V[], int a, int b, int w) {
    edge e;
    e.b = b;
    e.w = w;
    V[a].push_back(e);
    e.b = a;
    V[b].push_back(e);
    return;
}

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        vector<edge> V[3001];
        int T[3001];
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int a, b, w;
            edge e;
            cin >> a >> b >> w;
            add_edge(V, a, b, w);
        }
        for (int i = 1; i <= n; i++) T[i] = -1;
        int s;
        cin >> s;
        dijkstra(V, T, s, n);
        for (int i = 1; i <= n; i++) {
            if (i != s) cout << T[i] << " ";
        }
        cout << endl;
    }
    return 0;
}