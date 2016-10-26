#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s = "";
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        s += c;
    }
    size_t pos = s.find("010");
    int result = 0;
    while (pos != string::npos) {
        result++;
        s[pos + 2] = '1';
        pos = s.find("010");
    }
    cout << result << endl;
    return 0;
}