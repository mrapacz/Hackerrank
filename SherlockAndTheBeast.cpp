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
        int ilosc = n;
        bool found = false;
        while(ilosc >= 0)
        {
            if(ilosc % 3 == 0 and (n-ilosc)%5 == 0)
            {
                found = true;
                break;
            }
            ilosc--;
        }
        if(found)
        {
            for(int i = 0; i < ilosc; i++)
                cout << 5;
            for(int i = 0; i < n-ilosc; i++)
                cout << 3;
        }
        else cout << -1;
        cout << endl;
    }

    return 0;
}
