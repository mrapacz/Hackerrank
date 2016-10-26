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
    long long int result = 0;
    result += T[0] * (T[0] - 1) / 2;
    for (int i = 1; i <= (k - 1) / 2; i++) {
        result += T[i] * T[k - i];
    }
    if (k % 2 == 0) result += T[k / 2] * (T[k / 2] - 1) / 2;
    cout << result << endl;
    return 0;
}