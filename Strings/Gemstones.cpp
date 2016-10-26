#include <iostream>

using namespace std;

int main() {
    int result[26] = {0};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int local[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a';
            if (local[x] == 0) local[x] = 1;
        }
        for (int i = 0; i < 26; i++)
            result[i] += local[i];
    }
    int sum = 0;
    for (int i = 0; i < 26; i++)
        if (result[i] == n) sum++;
    cout << sum << endl;
    return 0;
}
