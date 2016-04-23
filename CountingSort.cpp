#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int T[100] = {0};
    int indexes[100] = {0};
    vector<pair<int, string> > V;
    vector<pair<int, string> > result(n);

    //input
    for (int i = 0; i < n; i++) {
        pair<int, string> a;
        cin >> a.first >> a.second;
        T[a.first]++;

        if (i < n / 2) a.second = "-";
        V.push_back(a);
    }


    //index table
    int writing_index = 0;
    for (int i = 0; i < 100; i++) {
        indexes[i] = writing_index;
        writing_index += T[i];
    }

    //sorting
    for (int i = 0; i < n; i++) {
        int ind = indexes[V[i].first];
        result[ind] = V[i];
        indexes[V[i].first]++;
    }

    //printing
    for (int i = 0; i < n; i++)
        cout << result[i].second << " ";
    cout << endl;
    return 0;
}