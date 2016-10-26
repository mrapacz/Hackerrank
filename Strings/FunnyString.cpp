#include <iostream>

using namespace std;

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        bool flag = true;
        string s;
        cin >> s;
        for (int i = 1; i < s.size(); i++) {
            if (abs(s[i] - s[i - 1]) != abs(s[s.size() - i] - s[s.size() - i - 1])) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "Funny" << endl;
        else cout << "Not Funny" << endl;
    }
    return 0;
}