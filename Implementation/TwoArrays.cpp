#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void func()
{
    int n,k;
    cin >> n;
    cin >> k;
    vector <int>A,B;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        B.push_back(a);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    bool impossible = false;
    for(int i = 0; i < n; i++)
    {
        if(A[i]+B[n-i-1] < k) impossible = true;
    }
    if(impossible) cout <<"NO";
    else cout <<"YES";
    cout << endl;

}
int main() {
    int Z;
    cin >> Z;
    while(Z--) func();
    return 0;

}

