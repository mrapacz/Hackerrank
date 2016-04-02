#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool operator<(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) return true;
    else return false;
}

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        vector<pair<int, int> > V;
        int m, n;
        cin >> m >> n;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            pair<int, int> x;
            x.first = a;
            x.second = i + 1;
            V.push_back(x);
        }
        sort(V.begin(), V.end());
        int i = 0;
        int j = V.size() - 1;
        while (i < j) {
            if (V[i].first + V[j].first > m) j--;
            else if (V[i].first + V[j].first < m) i++;
            else {
                if (V[i].second > V[j].second) swap(i, j);
                cout << V[i].second << " " << V[j].second << endl;
                break;
            }
        }
    }
    return 0;
}
