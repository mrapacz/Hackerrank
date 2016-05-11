#include<algorithm>
#include <vector>
#include<iostream>
using namespace std;
int main()
{
    int Z;
    cin >> Z;
    while(Z--)
    {
        int n;
        cin >> n;
        vector<vector<int> > A;
        for(int i = 0; i < n; i++)
        {
            vector<int> V;
            for(int j = 0; j < n; j++)
            {
                char a;
                cin >> a;
                V.push_back(a);
            }
            sort(V.begin(), V.end());
            A.push_back(V);
        }
        bool ok;
        for(int i = 0; i < n; i++)
        {
            ok = true;
            vector<int> V;
            for(int j = 1; j < n; j++)
            {
                if(A[i][j-1] > A[i][j] or A[j-1][i] > A[j][i])
                {
                    ok = false;
                    break;
                }
            }
            if(!ok) break;
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}
