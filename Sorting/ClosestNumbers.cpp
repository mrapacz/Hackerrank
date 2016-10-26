#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long int> V;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        V.push_back(a);
    }
    sort(V.begin(), V.end());
    long long int min = 100000000;
    for (int i = 1; i < V.size(); i++)
        min = min < V[i] - V[i - 1] ? min : V[i] - V[i - 1];

    for (int i = 1; i < V.size(); i++)
        if (V[i] - V[i - 1] == min) cout << V[i - 1] << " " << V[i] << " ";

    return 0;
}
