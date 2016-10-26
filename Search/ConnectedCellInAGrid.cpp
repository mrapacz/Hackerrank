#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool possible(int i, int j, int rows, int columns, vector<vector<int> > V) {
    return i >= 0 and j >= 0 and i < rows and j < columns and V[i][j] == 1;
}

void nextmove(int &i, int &j, int n) {
    if (n == 0) i++;
    if (n == 1) j++;
    if (n == 2) i--;
    if (n == 3) i--;
    if (n == 4) j--;
    if (n == 5) j--;
    if (n == 6) i++;
    if (n == 7) i++;
}

int BFS(int s, int d[], vector<int> G[]) {
    int size = 1;
    d[s] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int current = Q.front();
        Q.pop();
        for (int i = 0; i < G[current].size(); i++) {
            int adj = G[current][i];
            if (d[adj] == -1) {
                d[adj] = d[current] + 1;
                Q.push(adj);
                size++;
            }
        }
    }
    return size;
}

int main() {
    int rows, columns;
    cin >> rows >> columns;
    vector<vector<int> > T(10, vector<int>(10));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> T[i][j];
        }
    }
    vector<int> G[101];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (T[i][j] == 0) continue;
            int m = i, n = j;
            for (int k = 0; k < 8; k++) {
                nextmove(m, n, k);
                if (possible(m, n, rows, columns, T)) G[i * columns + j].push_back(m * columns + n);
            }
        }
    }

    int d[101];
    for (int i = 0; i < 101; i++) {
        d[i] = -1;
    }
    int result = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (T[i][j] == 1 and d[(i * columns) + j] == -1) result = max(result, BFS((i * columns) + j, d, G));
        }
    }

    cout << result << endl;
    return 0;
}