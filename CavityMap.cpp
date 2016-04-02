#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int> > V;
    for (int i = 0; i < n; i++) {
        vector<int> B;
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            int a = s[j] - '0';
            B.push_back(a);
        }
        V.push_back(B);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = V[i][j];
            if (i > 0 and j > 0 and i < n - 1 and j < n - 1 and V[i - 1][j] < x and V[i + 1][j] < x and
                V[i][j + 1] < x and V[i][j - 1] < x)
                cout << "X";
            else cout << x;
        }
        cout << endl;
    }
    return 0;
}
