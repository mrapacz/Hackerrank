#include <vector>
#include <iostream>

using namespace std;
struct tpair {
    int val;
    bool tpair;
};

int main() {
    int N;
    cin >> N;
    vector<tpair> V;
    for (int i = 0; i < N; i++) {
        tpair a;
        cin >> a.val;
        a.tpair = false;
        for (int i = 0; i < V.size(); i++) {
            if (V[i].val == a.val) {
                V[i].tpair = true;
                a.tpair = true;
            }
        }
        V.push_back(a);
    }
    for (int i = 0; i < V.size(); i++)
        if (V[i].tpair == false)
            cout << V[i].val << endl;
    return 0;
}
