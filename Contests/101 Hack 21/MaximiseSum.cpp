#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

//used during substraction to acquire math modulo
long long int euclidean_reminder(long long int a, long long int b) {
    long long int r = a % b;
    return r >= 0 ? r : r + abs(b);
}

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        int n;
        long long int m;
        cin >> n >> m;
        vector<long long int> V(n);
        for (int i = 0; i < n; i++)
            cin >> V[i];

        vector<long long int> prefix(n);
        set<long long int> S;

        long long int current_sum = 0;
        for (int i = 0; i < n; i++) {
            current_sum = euclidean_reminder((current_sum + V[i]), m);
            prefix[i] = current_sum;
        }

        long long int result = 0;
        for (int i = 0; i < n; i++) {
            long long int current_prefix = prefix[i] % m;
            result = max(result, current_prefix);
            set<long long int>::iterator it = S.upper_bound(current_prefix);
            if (it != S.end()) {
                result = max(result, euclidean_reminder(current_prefix - *it, m));
            }
            S.insert(current_prefix);
        }
        cout << result << endl;
    }
    return 0;
}