#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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
    return;
}


int main() {
    map<int, int> M;
    int T;
    cin >> T;
    while (T--) {

        int n, m;
        cin >> n;
        vector<edge> V[101];
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            add_edge(V, a, b, 0);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            add_edge(V, a, b, 0);
        }


        for (int i = 1; i <= 99; i++) {
            if (V[i].size() != 0) continue;
            for (int j = 1; j <= 6; j++) {
                if (i + j > 100) break;
                add_edge(V, i, i + j, 1);
            }
        }
        int d[101];
        for (int i = 1; i <= 100; i++)
            d[i] = -1;
        dijkstra(V, d, 1, 101);
        cout << d[100] << endl;
    }
    return 0;
}