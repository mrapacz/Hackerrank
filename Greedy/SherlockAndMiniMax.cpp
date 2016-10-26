#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

int search_min(int M, vector<int> V) {
    int result = (1 << 31) - 1;
    vector<int>::iterator x = upper_bound(V.begin(), V.end(), M);
    if (x != V.end()) {
        result = abs(M - *x);
    }
    if (x != V.begin()) result = min(result, abs(*(--x) - M));
    return result;
}

vector<int> get_m_vector(vector<int> V, int a, int b) {
    vector<int> M;
    M.push_back(a);
    M.push_back(b);
    for (int i = 0; i < V.size() - 1; i++) {
        int stop = (V[i] + V[i + 1]) / 2;
        if (stop >= a and stop <= b)
            M.push_back(stop);
    }
    sort(M.begin(), M.end());
    return M;
}

int find_m(int left, int right, vector<int> V) {
    int bestResult = -1;
    int best;
    int result;
    
    vector<int> M = get_m_vector(V, left, right);
    
    for (int j = 0; j < M.size(); j++) {
        int i = M[j];
        result = search_min(i, V);
        if (result > bestResult) {
            best = i;
            bestResult = result;
        }
    }
    return best;
}

int main() {
    vector<int> V;
    int n, a;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a;
        V.push_back(a);
    }

    int left, right;
    cin >> left >> right;
    
    sort(V.begin(), V.end());
    
    cout << find_m(left, right, V) << endl;
    return 0;
}
