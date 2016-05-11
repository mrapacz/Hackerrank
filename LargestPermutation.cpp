#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int index[n + 1];
    vector<int> V;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        V.push_back(a);
        index[a] = i;
    }

    for (int i = 0; (i < n) and (k > 0); i++) {
        if (V[i] == n - i) continue;
        V[index[n - i]] = V[i];
        index[V[i]] = index[n - i];
        V[i] = n - i;
        index[n - i] = i;
        k--;
    }
    for (int i = 0; i < V.size(); i++) {
        cout << V[i] << " ";
    }
    cout << endl;
    return 0;

}