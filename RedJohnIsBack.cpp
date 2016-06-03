#include <iostream>
#include <algorithm>

using namespace std;

int count_configurations(int n) {
    int T[n + 1];
    for (int i = 0; i <= n; i++) T[i] = 0;
    T[0] = 1;
    for (int i = 0; i < n; i++) {
        T[i + 1] += T[i];
        if (i + 4 <= n) T[i + 4] += T[i];
    }
    return T[n];
}

bool is_prime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int count_primes(int m) {
    int result = 0;
    for (int i = 2; i <= m; i++) {
        result += is_prime(i);
    }
    return result;
}

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        int n;
        cin >> n;
        int m = count_configurations(n);
        cout << count_primes(m) << endl;
    }
    return 0;
}