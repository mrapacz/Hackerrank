#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int n;
    cin >> n;
    vector <int>V;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        V.push_back(a);
    }
    sort(V.begin(), V.end());
    int bought = -1;
    int result = 0;
    int i = 0;
    while(i < V.size())
    {
        if(V[i] > bought)
        {
            bought = V[i] + 4;
            result++;
        }
        i++;
    }
    cout << result;
    return 0;

}
