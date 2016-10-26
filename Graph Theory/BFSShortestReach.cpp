#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printVector(vector<int> V) {
    for (int i = 0; i < V.size(); i++)
        cout << V[i] << " ";
    cout << endl;
}

void BFS(int s, int T[], vector<int> V[]) {
    T[s] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int current = Q.front();
        Q.pop();
        for (unsigned int i = 0; i < V[current].size(); i++) {
            int next = V[current][i];
            if (T[next] == -1) {
                Q.push(next);
                T[next] = T[current] + 1;
            }
        }

    }
}

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        int T[1001];
        for (int i = 0; i < 1001; i++)
            T[i] = -1;
        int n, m;
        cin >> n >> m;
        vector<int> V[1001];
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            V[a].push_back(b);
            V[b].push_back(a);
        }
        int S;
        cin >> S;
        BFS(S, T, V);
        for (int i = 1; i <= n; i++)
            if (i != S) {
                if (T[i] != -1) cout << T[i] * 6 << " ";
                else cout << T[i] << " ";
            }
        cout << endl;
    }
    return 0;
}
