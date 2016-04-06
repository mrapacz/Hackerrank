//
// Created by maciej on 06.04.16.
//
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
struct edge {
    int b;
    int w;
};

int tree_size(vector<int> V[], int s) {
    queue<int> Q;
    int count = 0;
    Q.push(s);
    set<int> seen;
    while (!Q.empty()) {
        count++;
        int current = Q.front();
        Q.pop();
        seen.insert(current);
        for (int i = 0; i < V[current].size(); i++) {
            int g = V[current][i];
            if (seen.find(g) == seen.end()) {
                Q.push(g);
                seen.insert(g);
            }
        }
    }
    return count;
}

void rmv_from_vector(vector<int> &V, int a) {
    vector<int>::iterator p = find(V.begin(), V.end(), a);
    V.erase(p);
    return;
}

void print_tree(vector<int> V[], int n) {
    for (int i = 1; i <= n; i++) {
        cout << "Current i: " << i << endl;
        for (int j = 0; j < V[i].size(); j++) {
            cout << "\t " << i << " " << V[i][j] << endl;
        }
    }
}
int rmv_edge(vector<edge>V[], int a, int b)
{
    int w = 0;
    for(int i = 0; i < V[a].size(); i++)
    {
        edge current = V[a][i];
        if(current.b == b){
            w = current.w;
            //todo: sklepac dijkstre
        }
    }
    return w;
}
int main() {
    vector<edge> V[200000];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        edge e;
        cin >> a >> b >> w;
        e.b = b;
        e.w = w;
        V[a].push_back(e);
        e.b = a;
        V[b].push_back(e);
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
        cout << dijkstra(V,s,d);

    }

    //print_tree(V, n);
    return 0;
}