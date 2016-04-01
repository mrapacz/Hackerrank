//
// Created by maciej on 24.03.16.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void printVector(vector<int> V) {
    for (int i = 0; i < V.size(); i++)
        cout << V[i] << " ";
    cout << endl;
}

void printPairVector(vector<pair<int, int> > V) {
    for (int i = 0; i < V.size(); i++)
        cout << "(" << V[i].first << ", " << V[i].second << ") ";
    cout << endl;
}

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        int n;
        vector<int> V;
        vector<pair<int, int> > P;
        set<int> S;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            V.push_back(a);
            S.insert(a);
        }

        sort(V.begin(), V.end());
        for (set<int>::iterator i = S.begin(); i != S.end(); i++) {
            pair<int, int> a;
            a.first = *i;
            a.second = (int) count(V.begin(), V.end(), a.first);
            P.push_back(a);
        }
        printPairVector(P);
        cout << endl;

    }
    return 0;
}