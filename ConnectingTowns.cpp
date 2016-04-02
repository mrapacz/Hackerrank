#include <iostream>
using namespace std;
int main()
{
    int Z;
    cin >> Z;
    while(Z--)
    {
        int N;
        cin >> N;
        long long int iloczyn = 1;
        for(int i = 0; i < N-1; i++)
        {
            int a;
            cin >> a;
            iloczyn = (iloczyn * a)%1234567;
        }
        cout << iloczyn << endl;
    }
}
