#include <vector>
#include <algorithm>
#include <iostream>

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
    if (n % 2 == 0) cout << (V[n / 2] + V[(n / 2) - 1]) / 2 << endl;
    else cout << V[n / 2] << endl;
    return 0;
}
