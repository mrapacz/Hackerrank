#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

long long int final_index(map<long long int, long long int> &M, int n) {
    int index = n;
    int k = -n;
    while (index != 0) {
        k++;
        index = M[index];
        index--;
    }
    return k;
}

int main() {
    long long int n, m;
    cin >> n >> m;
    map<long long int, long long int> M;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        M[a] = i;
    }
    
    cout << (long long int) (m - final_index(M, n)) << endl;
    return 0;
}