//
// Created by maciej on 24.03.16.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool enoughEnergy(long long int energy, vector<int> V) {
    for (int i = 0; i < V.size(); i++) {
        int diff = abs(energy - V[i]); //difference between height and energy lvl

        if (V[i] > energy) energy -= diff;
        else energy += diff;

        if (energy < 0) return false;
    }
    return true;
}

int binSearch(int a, int b, vector<int> V) {
    if (b - a == 1) return b;
    int mid = (a + b) / 2;
    if (enoughEnergy(mid, V)) b = mid;
    else a = mid;
    return binSearch(a, b, V);
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

    long long int maxEnergy;
    maxEnergy = *max_element(V.begin(), V.end());
    cout << binSearch(0, maxEnergy, V) << endl;
    return 0;
}