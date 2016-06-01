#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        int n;
        cin >> n;
        vector<int> shares;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            shares.push_back(a);
        }
        int maximum = shares[shares.size() - 1];
        long long result = 0;
        for (int i = shares.size() - 2; i >= 0; i--) {
            if (shares[i] < maximum) {
                result += maximum - shares[i];
            }
            else {
                maximum = shares[i];
            }
        }
        cout << result << endl;
    }
    return 0;
}