#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ranks, candies;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ranks.push_back(a);
        candies.push_back(1);
    }
    for (int i = 0; i < n - 1; i++) {
        if (ranks[i] < ranks[i + 1] and !(candies[i] < candies[i + 1])) {
            candies[i + 1] = candies[i] + 1;
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        if (ranks[i - 1] > ranks[i] and !(candies[i - 1] > candies[i]))
            candies[i - 1] = candies[i] + 1;
    }
    long long int sum = 0;
    for (int i = 0; i < n; i++)
        sum += candies[i];
    cout << sum << endl;
    return 0;
}