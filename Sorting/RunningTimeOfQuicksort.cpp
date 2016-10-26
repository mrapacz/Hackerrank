#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int qs_count = 0;
int shift_count = 0;

ostream &operator<<(ostream &o, vector<int> &V) {
    for (int i = 0; i < V.size(); i++) {
        o << V[i] << " ";
    }
    return o;
}

void quicksort(vector<int> &V, int a, int b) {
    if (a >= b) return;
    int i = a - 1, j = a;
    int pivot = V[b];
    while (j < b) {
        if (V[j] < pivot) {
            i++;
            //cout << "Swap in " << a << " to " << b  << endl;
            //cout << "from " << i << "to " << j << endl;
            swap(V[i], V[j]);
            qs_count++;
        }
        j++;
    }
    i++;
    swap(V[i], V[b]);
    qs_count++;
    quicksort(V, a, i - 1);
    quicksort(V, i + 1, b);
}

void insert(vector<int> &V, int n) {
    int sought = V[n - 1];
    int i = n - 1;
    while (i > 0) {
        V[i] = V[i - 1];
        if (V[i - 1] <= sought) {
            V[i] = sought;
            break;
        }
        i--;
        shift_count++;
    }
    if (i == 0) V[i] = sought;
}

void insertion_sort(vector<int> V) {
    for (int i = 1; i < V.size(); i++)
        insert(V, i + 1);
}


int main() {
    int n;
    cin >> n;
    vector<int> V, W;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        V.push_back(a);
        W.push_back(a);
    }
    quicksort(V, 0, n - 1);
    insertion_sort(W);
    cout << shift_count - qs_count << endl;
    return 0;
}
