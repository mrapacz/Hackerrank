//
// Created by maciej on 28.03.16.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> a, vector<int> b) {
    vector<int> c;
    int carry = 0;
    for (int i = 0; i < max(a.size(), b.size()); i++) {
        int sum = carry;
        if (i < a.size()) sum += a[i];
        if (i < b.size()) sum += b[i];
        carry = sum / 10;
        c.push_back(sum % 10);
    }
    if (carry > 0) c.push_back(carry);
    return c;
}

long long int fibonacciNth(long long int a, long long int b, int N) {
    if (N == 1) return a;
    if (N == 2) return b;
    long long int c;
    int i = 2;
    while (i < N) {
        c = a + b * b;
        a = b;
        b = c;
        i++;
    }
    return b;
}

int main() {
    int a, b;
    int n;
    cin >> a >> b >> n;
    cout << fibonacciNth(a, b, n) << endl;
    return 0;
}