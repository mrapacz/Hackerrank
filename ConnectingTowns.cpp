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
        long long int multip = 1;
        for(int i = 0; i < N-1; i++)
        {
            int a;
            cin >> a;
            multip = (multip * a)%1234567;
        }
        cout << multip << endl;
    }
}
