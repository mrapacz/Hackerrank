#include <iostream>

using namespace std;

int main() {
    int N, Z;
    int T[100000];
    cin >> N >> Z;
    for (int i = 0; i < N; i++)
        cin >> T[i];
    while (Z--) {
        int i, j;
        int min = 3;
        cin >> i >> j;
        for (i; i <= j; i++)
            min = T[i] < min ? T[i] : min;
        cout << min << endl;
    }
    return 0;
}
