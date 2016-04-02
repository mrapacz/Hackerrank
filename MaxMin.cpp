#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int>V;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        V.push_back(a);
    }
    sort(V.begin(), V.end());
    long long min = 1000000000;
    for(int i = k-1; i < n; i++)
    {
        if(V[i] - V[i-k+1] < min)
            min = V[i] - V[i-k+1];
    }
    cout << min << endl;
    return 0;
}
