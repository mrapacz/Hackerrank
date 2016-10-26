#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct tpair {
    int first;
    int second;
};

bool operator<(tpair A, tpair B) {
    if (A.second < B.second) return true;
    if (A.second > B.second) return false;
    else return (A.first < B.first);
}

int main() {
    int n;
    cin >> n;
    vector<tpair> V;
    for (int i = 0; i < n; i++) {
        tpair T;
        int a, b;
        cin >> a >> b;
        T.first = i + 1;
        T.second = a + b;
        V.push_back(T);
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < V.size(); i++)
        cout << V[i].first << " ";
    return 0;
}
