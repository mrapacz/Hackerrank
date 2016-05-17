#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> V;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        V.push_back(a);
    }
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    int i = 0;
    bool found = false;
    while (!found and i < V.size() - 2) {
        if (V[i] < V[i + 1] + V[i + 2]) {
            found = true;
            cout << V[i + 2] << " " << V[i + 1] << " " << V[i] << endl;
        }
        i++;
    }
    if (!found) cout << -1 << endl;
    return 0;
}