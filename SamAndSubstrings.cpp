#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    long long int result = 0;
    long long int mod = 1000000007;

    long long int factor = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        int current_digit = s[i] - '0';

        result = (result + (((current_digit * factor) % mod) * (i + 1)) % mod);
        result %= mod;

        factor = (factor * 10 + 1) % mod;
    }
    cout << result << endl;
    return 0;
}