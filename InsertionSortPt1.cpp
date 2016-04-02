#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> V) {
    for (int i = 0; i < V.size(); i++)
        cout << V[i] << " ";
    cout << endl;
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
    int sought = V[n - 1];
    int i = n - 1;
    while (i > 0) {
        V[i] = V[i - 1];
        if (V[i - 1] < sought) {
            V[i] = sought;
            break;
        }
        i--;
        print(V);
    }
    if (i == 0) V[i] = sought;
    print(V);
    return 0;
}
