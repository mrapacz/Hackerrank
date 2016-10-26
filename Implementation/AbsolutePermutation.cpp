#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        int n, k;
        cin >> n >> k;
        if (k == 0) {
            for (int i = 1; i <= n; i++) cout << i << " ";
            cout << endl;
            continue;
        }
        if (n % (2 * k) == 0) {
            int m = 1;
            for (int i = 0; i < n / (2 * k); i++) {
                for (int j = 0; j < k; j++) {
                    cout << m + j + k << " ";
                }
                for (int j = 0; j < k; j++) {
                    cout << m + j << " ";
                }
                m += 2 * k;
            }
            cout << endl;
        }
        else cout << -1 << endl;

    }
    return 0;
}
