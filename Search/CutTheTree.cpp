#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

void DFS(int s, vector<int> V[], int values[], bool visited[]) {
    int sum_of_tree = 0;
    visited[s] = true;
    for (int i = 0; i < V[s].size(); i++) {
        int current_child = V[s][i];
        if (visited[current_child]) continue;

        DFS(current_child, V, values, visited); //update child_set
        sum_of_tree += values[current_child];
    }
    values[s] += sum_of_tree;

}

int main() {
    int n;
    int s;
    cin >> n;
    vector<int> V[100001];
    int values[100001];
    bool visited[100001] = {false}, visited2[100001] = {false};

    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        if (i == 0) s = a;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    DFS(s, V, values, visited);

    int best_cut = numeric_limits<int>::max();
    for (int i = 1; i <= n; i++)
        best_cut = min(abs(values[s] - 2 * values[i]), best_cut); //update child_set

    cout << best_cut << endl;

    return 0;
}