#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void print_vector(vector<char> V) {
    for (int i = 0; i < V.size(); i++)
        cout << V[i];
    cout << endl;
}

void change(vector<char> &V, vector<char>::iterator i) {
    int prog = *i;
    int min = 1000;
    vector<char>::iterator mini = V.end(), it = i;

    while (i != V.begin()) {
        i--;
        if (*i > prog and *i < min) {
            min = *i;
            mini = i;
        }
    }
    swap(*it, *mini);
    sort(V.begin(), it);
    reverse(V.begin(), it);
}

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        vector<char> V;
        string s;
        cin >> s;
        string x = s;
        for (int i = 0; i < s.size(); i++)
            V.push_back(s[s.size() - i - 1]);
        bool found = false;

        vector<char>::iterator i = V.begin();
        i++;
        while (i != V.end()) {
            if (*i < *(i - 1)) {
                found = true;
                change(V, i);
                reverse(V.begin(), V.end());
                break;
            }
            i++;
        }
        if (found)
            for (int i = 0; i < V.size(); i++)
                cout << V[i];
        else cout << "no answer";
        cout << endl;
    }
    return 0;
}
