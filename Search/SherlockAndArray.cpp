#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int Z;
    cin >> Z;
    while(Z--)
    {
        int n;
        int left = 0, right = 0;
        cin >> n;
        vector <int> V;
        for(int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            right += a;
            V.push_back(a);
        }
        bool possible = false;
        for(int i = 0; i < V.size(); i++)
        {
            right -= V[i];
            if(left == right)
                possible = true;
            left += V[i];
        }
        if(possible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;   
}
