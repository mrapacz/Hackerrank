#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    set<int> S;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        S.insert(a);
    }
    int sum = 0;
    for (set<int>::iterator it = S.begin(); it != S.end(); it++)
        if (S.find(*it + k) != S.end()) sum++;
    cout << sum << endl;

    return 0;
}
