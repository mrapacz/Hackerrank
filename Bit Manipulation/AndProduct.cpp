//
// Created by maciej on 16.04.16.
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        long long int a, b;
        cin >> a >> b;
        //if binary representation of two numbers is of different length, return 0
        if (int(log2(a)) != int(log2(b))) {
            cout << 0 << endl;
            continue;
        }

        long long int result = 0;
        int i = (int) log2(a);

        //take the first n digits that are the same in two numbers and return as result
        while (i >= 0) {
            long long int current_digit = (1ULL << i);
            if ((current_digit & a) != (current_digit & b)) break;
            if (current_digit & a) result += current_digit;
            i--;
        }
        cout << result << endl;
    }
    return 0;
}