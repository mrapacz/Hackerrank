#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int left(vector<int> &V) {
    int i = 0;
    while (V[i] <= 0 and i < V.size())
        i++;
    return V.size() - i;
}

int main() {
    vector<int> V;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        V.push_back(a);
    }
    sort(V.begin(), V.end());
    while (left(V) > 0) {
        cout << left(V) << endl;
        int i = 0;
        while (V[i] <= 0)
            i++;
        int min = V[i];
        for (i; i < V.size(); i++)
            V[i] -= min;
    }

    return 0;
}
