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

int DFS2(int s, vector<int> V[], int values[], bool visited[], int global_sum) {
    visited[s] = true;
    int best = numeric_limits<int>::max();

    for (int i = 0; i < V[s].size(); i++) {
        int current_child = V[s][i];
        if (visited[current_child]) continue;

        int child_best = DFS2(current_child, V, values, visited, global_sum);
        best = min(abs(global_sum - 2 * values[current_child]), child_best); //update child_set
    }
    return best;
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
    cout << DFS2(s, V, values, visited2, values[s]) << endl;

    return 0;
}