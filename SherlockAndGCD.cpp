#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

void divisors(int a, vector<int> &V) {
    if (a == 1) return;
    int b = a;
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            V.push_back(i);
        }
        while (a % i == 0)
            a = a / i;
    }
    if (a != 1) V.push_back(a);
}

void check(int a, vector<int> &V) {
    for (vector<int>::iterator i = V.begin(); i < V.end(); i++) {
        if (a % (*i) != 0) V.erase(i);
    }
}

int main() {
    int Z;
    cin >> Z;
    int T[100];
    while (Z--) {
        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> T[i];

        vector<int> V;
        divisors(T[0], V);

        for (int i = 1; i < N; i++) {
            check(T[i], V);
        }

        if (V.size() == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
