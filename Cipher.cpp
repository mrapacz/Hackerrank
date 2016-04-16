//
// Created by maciej on 16.04.16.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    vector<int> V;
    for (int i = 1; i < k; i++)
        V.push_back(0);


    int last_value = 0;
    bool odd;

    for (int i = 0; i < n; i++) {

        int current_digit = s[i] - '0';
        if (last_value) odd = !odd;

        if (odd != current_digit) {
            V.push_back(1);
            odd = current_digit;
        }
        else {
            V.push_back(0);
            odd = current_digit;
        }

        last_value = V[i];
    }
    for (int i = k - 1; i < k - 1 + n; i++)
        cout << V[i];
    cout << endl;
    return 0;
}