//
// Created by maciej on 17.04.16.
//
#include <iostream>
#include <queue>

using namespace std;

int bfs(vector<int> V[], int s, bool visited[]) {

    visited[s] = true;
    queue<int> Q;
    int graph_size = 0;
    Q.push(s);
    while (!Q.empty()) {
        graph_size++;
        int current = Q.front();
        Q.pop();
        for (int i = 0; i < V[current].size(); i++) {
            int g = V[current][i];
            if (!visited[g]) {
                Q.push(g);
                visited[g] = true;
            }
        }
    }
    return graph_size;
}

int main() {
    vector<int> V[100000];
    bool visited[100000] = {false};

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    vector<int> countries;
    for (int i = 0; i < n; i++)
        if (!visited[i]) countries.push_back(bfs(V, i, visited));

    long long int square_sum = 0;
    long long int sum = 0;
    for (int i = 0; i < countries.size(); i++) {
        sum += countries[i];
        square_sum += countries[i] * countries[i];
    }
    long long int result = (sum * sum - square_sum) / 2;

    cout << result << endl;
    return 0;
}