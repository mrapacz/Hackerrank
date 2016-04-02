#include <iostream>

using namespace std;

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        string s;
        cin >> s;
        bool ok = true;
        for (int i = 0; i < 5; i++)
            if (s[i] >= 'A' and s[i] <= 'Z') continue;
            else {
                ok = false;
                break;
            }
        for (int i = 5; i < 9; i++) {
            if (s[i] < '0' or s[i] > '9') {
                ok = false;
                break;
            }
        }
        if (!(s[9] >= 'A' and s[9] <= 'Z')) {
            ok = false;
        }
        if (!ok) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
