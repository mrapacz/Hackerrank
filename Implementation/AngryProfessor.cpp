//
// Created by maciej on 03.04.16.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        vector<int> V;
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            V.push_back(a);
        }
        sort(V.begin(), V.end());
        int count = upper_bound(V.begin(), V.end(), 0) - V.begin();
        if(count < k) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}