#include<iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    long long int result = 0, rmnder = 0;
    for (int i = 0; i < m; i++) {
        long long int a, b, k;
        cin >> a >> b >> k;
        long long currnt = (b - a + 1) * k;
        rmnder += currnt % n;
        result += currnt / n + rmnder / n;
        rmnder = rmnder % n;
    }
    cout << result << endl;
    return 0;
}
