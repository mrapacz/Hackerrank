#include<iostream>
#include<vector>

using namespace std;
int W, K;

void print(vector<vector<char> > &V) {
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < K; j++) cout << V[i][j];
        cout << endl;
    }
}

bool moves(int x, int y, int &nw, int &nk, int i, vector<vector<char> > &V) {
    int wiersz[4] = {-1, 0, 1, 0};
    int kolumna[4] = {0, 1, 0, -1};
    nw = x + wiersz[i];
    nk = y + kolumna[i];
    return (nw >= 0 and nk >= 0 and nw < W and nk < K and V[nw][nk] != 'X');
}

int game(vector<vector<char> > &V, pair<int, int> &H, pair<int, int> &E, int x, int y) {
    V[x][y] = 'X';
    if (x == E.first and y == E.second) return 0;
    int ilosc = 0;
    int max_v = -1;
    for (int i = 0; i <= 3; i++) {
        int nw, nk;
        if (moves(x, y, nw, nk, i, V)) {
            ilosc++;
            int current = game(V, H, E, nw, nk);
            if (current >= max_v) max_v = current;
        }
    }
    if (ilosc > 1 and max_v >= 0) return max_v + 1;
    else return max_v;
}

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        pair<int, int> H, E;
        int w, k;
        cin >> w >> k;
        W = w;
        K = k;
        vector<vector<char> > T;
        for (int i = 0; i < w; i++) {
            char a;
            vector<char> V;
            for (int j = 0; j < k; j++) {
                cin >> a;
                if (a == 'M') {
                    H.first = i;
                    H.second = j;
                }
                if (a == '*') {
                    E.first = i;
                    E.second = j;
                }
                V.push_back(a);
            }
            T.push_back(V);
        }
        cin >> k;
        int m = game(T, H, E, H.first, H.second);
        if (m == k) cout << "Impressed";
        else cout << "Oops!";
        cout << endl;
    }
    return 0;
}
