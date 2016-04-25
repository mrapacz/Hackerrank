#include <iostream>
#include <algorithm>

using namespace std;

void fill_prefix_table(vector<int> V, vector<int> &prefix) {
    int sum = 0;
    prefix.push_back(0);
    for (int i = 0; i < n; i++) {
        sum += V[i];
        prefix.push_back(sum);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> V;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        V.push_back(a);
    }
    vector<int> prefix;
    fill_prefix_table(V, prefix);


    int querry_count;
    cin >> querry_count;
    for (int i = 0; i < querry_count; i++) {
        int q;
        cin >> q;

    }
    return 0;
}