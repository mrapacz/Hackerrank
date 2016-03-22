//Bear and steady gene

#include <iostream>
#include <map>
#include <limits>
#include <vector>

using namespace std;

void printV(vector<int> V) {
    for (int i = 0; i < V.size(); i++)
        cout << V[i] << " ";
    cout << endl;
}

int main() {
    int n;
    string s;
    map<char, int> M;
    M['G'] = 0;
    M['T'] = 1;
    M['A'] = 2;
    M['C'] = 3;


    cin >> n;
    cin >> s;

    int T[4] = {0};
    for (int i = 0; i < s.size(); i++)
        T[M[s[i]]]++;
    int sum = 0;

    for (int i = 0; i < 4; i++) {
        T[i] -= n / 4;
        if (T[i] > 0) sum += T[i];
    }

    vector<int> V;


    int min = std::numeric_limits<int>::max();

    for (int i = 0; i < s.size(); i++)
        if (T[M[s[i]]] > 0) V.push_back(i);


    for (int i = 0; i < V.size() - sum; i++) {
        int curr = V[i + sum - 1] - V[i] + 1;
        if (curr < min) {
            min = curr;
            //cout << "Score beaten for i = " << i << endl;
        }
    }
    //printV(V);
    cout << min << endl;
    return 0;
}