#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> V) {
    for (int i = 0; i < V.size(); i++)
        cout << V[i] << " ";
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
    vector<int> A, B;
    int p = V[0];
    for (int i = 1; i < V.size(); i++) {
        if (V[i] < p)
            A.push_back(V[i]);
        else
            B.push_back(V[i]);
    }
    print(A);
    cout << p << " ";
    print(B);

    return 0;
}
