#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
    int ind;
    int parent_ind;
};
struct edge {
    int start;
    int end;
    int w;
};

//operator is switched for proper sorting of priority_queue
bool operator<(const edge a, const edge b) {
    if (a.w != b.w) return a.w > b.w;
    return a.start + a.w + a.end > b.start + b.w + b.end;
}

ostream &operator<<(ostream &o, const node &a) {
    o << "index: " << a.ind << "\tparent ind: " << a.parent_ind << endl;
    return o;
}

ostream &operator<<(ostream &o, const edge &e) {
    o << "(" << e.start << ", " << e.end << ", " << e.w << ")" << endl;
    return o;
}

node make_set(int id) {
    node x;
    x.ind = id;
    x.parent_ind = id;
    return x;
}

int find(int ind, node T[]) {
    if (T[ind].parent_ind != T[ind].ind)
        T[ind].parent_ind = find(T[ind].parent_ind, T);

    return T[ind].parent_ind;
}

void union_sets(int x, int y, node T[]) {
    int xParent = find(x, T);
    int yParent = find(y, T);
    if (xParent == yParent) return;
    T[xParent].parent_ind = yParent;
}

void kruskal(vector<edge> edges, vector<edge> H[], node T[]) {

    priority_queue<edge> Q;
    for (int i = 0; i < edges.size(); i++)
        Q.push(edges[i]);
    while (!Q.empty()) {
        edge current = Q.top();
        Q.pop();
        if (find(current.start, T) != find(current.end, T)) {
            union_sets(current.start, current.end, T);

            //add the edge to the new graph
            H[current.start].push_back(current);
            swap(current.start, current.end);
            H[current.start].push_back(current);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    node T[n + 1];
    vector<edge> edges;
    for (int i = 0; i < m; i++) {
        edge e;
        cin >> e.start >> e.end >> e.w;
        edges.push_back(e);
    }
    int s;
    cin >> s;

    vector<edge> H[3001]; //new graph
    for (int i = 1; i <= n; i++) T[i] = make_set(i);
    kruskal(edges, H, T);
    return 0;
}