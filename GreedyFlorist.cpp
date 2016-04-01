#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n,k;
    cin >> n;
    cin >> k;
    vector <int>V;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        V.push_back(-a);
    }
    sort(V.begin(), V.end());
    int counter = 0;
    int mul = -1;
    long long result = 0;
    for(int i = 0; i < n; i++)
    {
        result += V[i] * mul;
        counter++;
        if(counter == k)
        {
            counter = 0;
            mul--;
        }
    }
    cout << result << endl;
    return 0;
}

