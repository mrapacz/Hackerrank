#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> V;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        V.push_back(a);
    }
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        int current = (a - k) % n;
        if (current < 0) current += n;
        cout << V[current] << endl;
    }
    return 0;
}
