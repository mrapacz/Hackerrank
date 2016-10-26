#include <cmath>
#include <string>
#include <iostream>

using namespace std;

void algo(string s, int n) {
    for (int i = 0; i < n; i++) {
        int x = i;
        while (x < s.size()) {
            cout << s[x];
            x += n;
        }
        cout << " ";
    }
    cout << endl;
}

int main() {
    string s;
    getline(cin, s);
    string ws;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != ' ') ws += s[i];
    int n = sqrt(ws.size());
    int k;
    if (n * n == ws.size()) algo(ws, n);
    else algo(ws, n + 1);
    return 0;
}
