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

    int moves = 0;
    for (int i = 0; i < n - 1; i++) {
        if (V[i] % 2 == 0) continue;
        else {
            moves += 2;
            V[i]++;
            V[i + 1]++;
        }
    }
    if (V[n - 1] % 2 == 0) cout << moves << endl;
    else cout << "NO" << endl;

    return 0;
}