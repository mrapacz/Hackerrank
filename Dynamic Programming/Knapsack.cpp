#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        int n, k;
        cin >> n >> k;
        vector<int> V;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            V.push_back(a);
        }
        bool T[k + 1];
        for (int i = 0; i <= k; i++) T[i] = false;
        T[0] = true;
        for (int i = 0; i < k; i++) {
            if (T[i]) {
                for (int j = 0; j < V.size(); j++) {
                    if (i + V[j] <= k) {
                        T[i + V[j]] = true;
                    }
                }
            }
        }

        bool found = false;

        int i;
        for (i = k; !found; i--)
            if (T[i]) found = true;

        cout << i << endl;
    }
    return 0;
}