#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string a = "", b = "";

        if (s.size() % 2 == 1) {
            cout << -1 << endl;
            continue;
        }

        for (int i = 0; i < s.size() / 2; i++)
            a = a + s[i];
        for (int i = s.size() / 2; i < s.size(); i++)
            b = b + s[i];

        int T[26];

        for (int i = 0; i < 26; i++) 
            T[i] = 0;
        for (int i = 0; i < a.size(); i++)
            T[a[i] - 'a']++;
        for (int i = 0; i < b.size(); i++)
            T[b[i] - 'a']--;
        int suma = 0;
        for (int i = 0; i < 26; i++)
            suma = T[i] > 0 ? suma + T[i] : suma;
        cout << suma << endl;
    }
    return 0;
}
