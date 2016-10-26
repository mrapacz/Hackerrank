#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int T[k];
    for (int i = 0; i < k; i++) T[i] = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        T[a % k]++;
    }
    long long int result = T[0] ? 1 : 0;

    for (int i = 1; i <= (k - 1) / 2; i++) {
        result += max(T[i], T[k - i]);
    }
    if (k % 2 == 0) result += T[k] ? 1 : 0;
    cout << result << endl;
    return 0;
}