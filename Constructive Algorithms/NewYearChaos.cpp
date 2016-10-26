#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        int n;
        cin >> n;

        int T[n + 1];
        for (int i = 1; i <= n; i++) {
            cin >> T[i];
        }
        bool bad_input = false;
        for (int i = 1; i <= n; i++) {
            if (T[i] - i > 2) bad_input = true;
        }
        if (bad_input) {
            cout << "Too chaotic" << endl;
            continue;
        }


        int result = 0;
        bool swapped = true;
        while (swapped) {
            swapped = false;
            for (int i = 1; i < n; i++) {
                if (T[i] > T[i + 1]) {
                    swap(T[i], T[i + 1]);
                    swapped = true;
                    result++;
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}