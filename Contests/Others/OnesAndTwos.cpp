#include <iostream>
#include <map>

using namespace std;

void get_possibilities(int ones, int twos, map<int, bool> &M, int result, int current_factor) {
    M[result + current_factor] = true;
    if (!ones and !twos) return;
    if (ones) get_possibilities(ones - 1, twos, M, result + current_factor, 1);
    if (twos) {
        get_possibilities(ones, twos - 1, M, result, current_factor * 2);
        get_possibilities(ones, twos - 1, M, result + current_factor, 2);
    }
}

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        int ones, twos;
        cin >> ones >> twos;
        map<int, bool> M;
        if (!ones and !twos) {
            cout << 0 << endl;
            continue;
        }
        if (ones) {
            M[1] = true;
            get_possibilities(ones - 1, twos, M, 0, 1);

        }
        if (twos) {
            M[2] = true;
            get_possibilities(ones, twos - 1, M, 0, 2);
        }
        long long int result = 0;
        for (map<int, bool>::iterator i = M.begin(); i != M.end(); i++) {
            if (i->second) result = (result + 1) % int(1E9 + 7);
        }
        cout << result << endl;
    }
    return 0;
}