#include <iostream>
#include <vector>

using namespace std;

void wypisz(vector<int> V) {
    for (int i = 0; i < V.size(); i++)
        cout << V[i] << " ";
    cout << endl;
}

void move(vector<int> &V, vector<int> A, vector<int> B, int p) {
    for (int i = 0; i < A.size(); i++)
        V.push_back(A[i]);
    V.push_back(p);
    for (int i = 0; i < B.size(); i++)
        V.push_back(B[i]);
}

void quicksort(vector<int> &V) {
    if (V.size() <= 1) return;
    vector<int> A, B;
    int p = V[0];
    for (int i = 1; i < V.size(); i++) {
        if (V[i] < p)
            A.push_back(V[i]);
        else
            B.push_back(V[i]);
    }
    quicksort(A);
    quicksort(B);
    vector<int> X;
    move(X, A, B, p);
    V = X;
    wypisz(V);
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
    quicksort(V);
    return 0;
}
