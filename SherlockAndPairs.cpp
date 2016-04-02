#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int Z;
    cin >> Z;
    while(Z--)
    {
        int n;
        cin >> n;
        vector<long long int> V;
        for(int i = 0; i < n; i++)
        {
            long long int a;
            cin >> a;
            V.push_back(a);
        }
        sort(V.begin(), V.end());
        int i = 0;
        long long int sum = 0;
        while(i < n)
        {
            int p = V[i];
            long long int count = 0;
            while(i < n and V[i] == p)
            {
                count++;
                i++;
            }
            sum+= count*(count-1);
        }
        cout << sum << endl;
    }
    return 0;
}
