#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> coins;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        coins.push_back(a);
    }
    sort(coins.begin(), coins.end());

    long long int T[251] = {1};

    for (int i = 0; i < coins.size(); i++) {
        int current_coin = coins[i];
        for (int j = 0; j + current_coin <= n; j++)
            T[j + current_coin] += T[j];

    }
    cout << T[n] << endl;
    return 0;
}