#include <iostream>
#include <set>
#include <ctype.h>

using namespace std;

int main() {
    set<char> S;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            char x = tolower(s[i]);
            if (S.find(x) == S.end())
                S.insert(x);
        }
    }
    if (S.size() == 26)
        cout << "pangram" << endl;
    else cout << "not pangram" << endl;

    return 0;
}