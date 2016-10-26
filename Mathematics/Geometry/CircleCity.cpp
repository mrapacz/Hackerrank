#include <cmath>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        int r, k;
        cin >> r >> k;
        int sum = 0;
        for (int i = 0; i < sqrt(r); i++) {
            int current = r - (i * i);
            int d = sqrt(current);
            if (d * d == current) {
                sum += 4;
            }
        }
        if (sum > k) cout << "impossible";
        else cout << "possible";
        cout << endl;

    }

    return 0;
}
