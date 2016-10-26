#include <iostream>
using namespace std;

int main()
{
    int Z;
    cin >> Z;
    while(Z--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        long long result = 1;
        if(a > b) swap(a,b);
        result = a*(n-1);
        cout << result << " ";

        if(a != b)
        {
            for(int i = 1; i < n; i++)
            {
                result = result - a + b;
                cout << result << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
