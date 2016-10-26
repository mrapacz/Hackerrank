#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{

    long long n, k; cin >> n >> k;
    vector<int> p;
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        p.push_back(a);
    }
    sort(p.begin(), p.end());
    int i = 0;
    while(k > 0 and i < p.size())
    {
       k = k-p[i];
       i++;
    }
    if(k < 0) i--;

    int answer = i;

    // Write the code for computing the final answer using n,k,prices

    cout << answer << endl;


    return 0;
}
