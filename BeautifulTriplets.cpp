#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    bool T[20001] = {0};
    int n, d;
    cin >> n >> d;
    vector<int> V;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        T[a] = true;
        V.push_back(a);
    }
    int max = V[n - 1];
    int result = 0;
    for (int i = 0; i < n; i++) {
        int current = V[i];
        if (current + 2 * d <= max and T[current + d] and T[current + 2 * d]) result++;
    }
    cout << result << endl;
    return 0;
}