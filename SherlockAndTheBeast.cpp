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
        int count = n;
        bool found = false;
        while(count >= 0)
        {
            if(count % 3 == 0 and (n-count)%5 == 0)
            {
                found = true;
                break;
            }
            count--;
        }
        if(found)
        {
            for(int i = 0; i < count; i++)
                cout << 5;
            for(int i = 0; i < n-count; i++)
                cout << 3;
        }
        else cout << -1;
        cout << endl;
    }

    return 0;
}
