#include <string>
#include <iostream>

using namespace std;

bool check(string a, string b) {
    bool T[26] = {false};
    for (int i = 0; i < a.size(); i++) {
        int s = a[i] - 97;
        T[s] = true;
    }
    for (int i = 0; i < b.size(); i++) {
        int s = b[i] - 97;
        if (T[s] == true) return true;
    }
    return false;
}

int main(int argc, char **argv) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a;
        cin >> b;
        if (check(a, b)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

