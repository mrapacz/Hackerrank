//
// Created by maciej on 07.04.16.
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        int ones = 0;
        int moves;
        unsigned long long n;
        cin >> n;
        int bit_count = int(log2(n)) + 1;
        bool leading_zeros = true;

        int zero_count = 0;
        for (int i = 0; i < bit_count; i++) {
            if ((1ULL << i) & n) {
                ones++;
                leading_zeros = false;
            }
            else if (leading_zeros) {
                zero_count++;
            }
        }
        if (n % 2) moves = ones - 1;
        else moves = zero_count + ones - 1;

        if (moves % 2) cout << "Louise" << endl;
        else cout << "Richard" << endl;

    }
    return 0;
}
