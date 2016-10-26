#include <iostream>
#include <vector>

using namespace std;

int find_continuous(vector<int> &V) {
    int sum = 0;
    int max_v = 0;
    for (int i = 0; i < V.size(); i++) {
        if (sum + V[i] >= 0) {
            sum += V[i];
            max_v = max_v < sum ? sum : max_v;
        }
        else
            sum = 0;
    }
    if (max_v == 0) {
        max_v = -100000;
        for (int i = 0; i < V.size(); i++)
            max_v = max_v < V[i] ? V[i] : max_v;
    }
    return max_v;
}

int find(vector<int> &V) {
    int sum = 0;
    for (int i = 0; i < V.size(); i++)
        sum += V[i] > 0 ? V[i] : 0;
    if (sum == 0) {
        sum = -100000;
        for (int i = 0; i < V.size(); i++)
            sum = sum < V[i] ? V[i] : sum;
    }
    return sum;
}

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        int n;
        cin >> n;
        vector<int> V;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            V.push_back(a);
        }
        cout << find_continuous(V) << " " << find(V) << endl;
    }
    return 0;
}
