#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int x, y;
    vector<int> A, B;
    cin >> x;
    for (int i = 0; i < x; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    cin >> y;
    for (int i = 0; i < y; i++) {
        int a;
        cin >> a;
        B.push_back(a);
    }
    int last = -1;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int i = 0, j = 0;
    int found = 0;
    while (i < A.size() and found < y - x) {
        if (A[i] != B[j]) {

            if (last != B[j]) cout << B[j] << " ";
            last = B[j];
            j++;
            found++;
        }
        else {
            i++;
            j++;
        }
    }
    if (found < y - x) {
        for (int i = j; i < B.size(); i++)
            cout << B[i] << " ";
    }
    cout << endl;
    return 0;
}
