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
    int a;
    int b;
    int w;
};
struct vec {
    int n;
    int dist;
};

int rmv_edge(vector<edge> V[], int a, int b) {
    int w = 0;
    for (vector<edge>::iterator i = V[a].begin(); i < V[a].end(); i++) {
        edge current = *i;
        if (current.b == b) {
            w = current.w;
            V[a].erase(i++);
        }
    }
    return w;
}

bool operator<(vec a, vec b) {
    return a.dist <= b.dist;
}

int dijkstra(vector<edge> V[], int s, int d) {

    map<int, int> M;
    M[s] = 0;
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
            if (M.find(next) == M.end() or M[current.n] + weight < M[next]) {
                M[next] = M[current.n] + weight;
                vec x;
                x.n = next;
                x.dist = M[next];
                Q.push(x);
            }
        }
    }
    if (M.find(d) == M.end()) return -1;
    else return M[d];
}

void add_edge(vector<edge> V[], int a, int b, int w) {
    edge e;
    e.a = a;
    e.b = b;
    e.w = w;
    V[a].push_back(e);
    swap(e.a, e.b);
    V[b].push_back(e);
    return;
}

int main() {
    vector<edge> V[200000];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        edge e;
        cin >> a >> b >> w;
        add_edge(V, a, b, w);
    }
    int s, d;
    cin >> s >> d;
    int Z;
    cin >> Z;
    while (Z--) {
        int a, b;
        cin >> a >> b;
        int w = rmv_edge(V, a, b);
        rmv_edge(V, b, a);
        cout << dijkstra(V, s, d) << endl;
        add_edge(V, a, b, w);
    }

    //print_tree(V, n);
    return 0;
}