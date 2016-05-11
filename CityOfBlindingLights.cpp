#include <iostream>
#include <algorithm>
#include <limits>
#include <queue>

using namespace std;

void floyd(vector<vector<long long int> > &d, int n) {
    int inf = numeric_limits<int>::max();
    //note: n := n+1, as V are indexed from 1
    for (int u = 1; u < n; u++) {
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (d[i][u] == inf or d[u][j] == inf) continue;
                if (d[i][j] > d[i][u] + d[u][j]) {
                    d[i][j] = d[i][u] + d[u][j];
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<long long int> > d(n + 1, vector<long long int>(n + 1));
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            d[i][j] = numeric_limits<int>::max();
        }
        d[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        long long int w;
        cin >> a >> b >> w;
        d[a][b] = w;
    }
    floyd(d, n + 1);

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (d[a][b] == numeric_limits<int>::max()) cout << -1 << endl;
        else cout << d[a][b] << endl;
    }

    return 0;
}