#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> V) {
    for (int i = 0; i < V.size(); i++)
        cout << V[i] << " ";
    cout << endl;
}

void insert(vector<int> &V, int n) {
    int sought = V[n - 1];
    int i = n - 1;
    while (i > 0) {
        V[i] = V[i - 1];
        if (V[i - 1] < sought) {
            V[i] = sought;
            break;
        }
        i--;
    }
    if (i == 0) V[i] = sought;
}

int main() {
    vector<int> V;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        V.push_back(a);
    }
    for (int i = 1; i < V.size(); i++)
        insert(V, i + 1);
    print(V);
    return 0;
}

