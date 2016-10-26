#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

ostream &operator<<(ostream &o, vector<int> &V) {
    for (int i = 0; i < V.size(); i++) {
        o << V[i] << " ";
    }
    return o;
}

void quicksort(vector<int> &V, int a, int b) {
    if (a >= b) return;
    int i = -1, j = 0;
    int pivot = V[b];
    while (j < b) {
        if (V[j] < pivot) {
            i++;
            swap(V[i], V[j]);
        }
        j++;
    }
    i++;
    swap(V[i], V[b]);
    cout << V << endl;
    quicksort(V, a, i - 1);
    quicksort(V, i + 1, b);
}

int main() {
    int n;
    cin >> n;
    vector<int> V;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        V.push_back(a);
    }
    quicksort(V, 0, n - 1);
    return 0;
}