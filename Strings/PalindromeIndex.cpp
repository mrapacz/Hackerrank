#include <iostream>

using namespace std;

bool check(string s, int x) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (i == x) i++;
        if (j == x) j--;
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        int ind = -1;
        string s;
        cin >> s;
    
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                if (s[i + 1] == s[j]) if (check(s, i)) ind = i;
                if (s[i] == s[j - 1]) if (check(s, j)) ind = j;
                break;
            }
            i++;
            j--;
        }
        cout << ind << endl;
    }
    return 0;
}
