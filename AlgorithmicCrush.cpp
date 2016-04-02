#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct tpair {
    int x;
    int count;
};

bool operator<(tpair a, tpair b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x and a.count < b.count) return true;
    else return false;
}

void print(vector<tpair> V) {
    for (int i = 0; i < V.size(); i++) {
        cout << V[i].x << " " << V[i].count << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<tpair> V;
    for (int i = 0; i < m; i++) {
        int a, b, k;
        cin >> a >> b >> k;
        tpair x;
        x.x = a;
        x.count = k;
        V.push_back(x);
        x.x = b + 1;
        x.count = -x.count;
        V.push_back(x);


    }
    sort(V.begin(), V.end());
    long long int sum = 0;
    long long int max_v = 0;
    for (int i = 0; i < V.size(); i++) {
        sum += V[i].count;
        max_v = max_v < sum ? sum : max_v;
    }
    cout << max_v << endl;

}
