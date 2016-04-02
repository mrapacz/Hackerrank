#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> get_divisors(int n) {
    vector<int> V;
    if (n == 1) {
        V.push_back(1);
        return V;
    }
    int i = 1;
    for (i; i < sqrt(n); i++) {
        if (n % i == 0) {
            V.push_back(n / i);
            V.push_back(i);
        }
    }
    if (i * i == n) V.push_back(i);

    return V;
}


int main() {

    long long int divisors[100001];
    for (int i = 0; i < 100001; i++) divisors[i] = 1;
    int n, m;
    cin >> n >> m;
    vector<long long int> A, B, C;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        B.push_back(a);
    }

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        divisors[B[i]] *= a;
        divisors[B[i]] %= 1000000007;
        C.push_back(a);
    }


    for (int i = 1; i <= n; i++) {
        vector<int> V;
        V = get_divisors(i);
        for (int j = 0; j < V.size(); j++) {

            A[i - 1] *= divisors[V[j]];
            A[i - 1] = A[i - 1] % 1000000007;
        }
    }
    for (int i = 1; i <= A.size(); i++)
        cout << A[i - 1] << " ";
    cout << endl;
    return 0;
}
