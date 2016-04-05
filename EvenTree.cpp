//
// Created by maciej on 05.04.16.
//
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

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

int main() {
    vector<int> V[101];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    bool change = true;
    int count = 0;
    while (change) {
        change = false;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < V[i].size(); j++) {
                int a = i;
                int b = V[i][j];

                rmv_from_vector(V[a], b);
                rmv_from_vector(V[b], a);

                if (tree_size(V, a) % 2 == 0 and tree_size(V, b) % 2 == 0) {
                    change = true;
                    count++;
                }
                else {
                    V[a].push_back(b);
                    V[b].push_back(a);
                }
            }
        }
    }
    cout << count << endl;
    //print_tree(V, n);
    return 0;
}