#include <iostream>
using namespace std;

int main()
{
    int Z;
    cin >> Z;
    while(Z--)
    {
        long long a;
        long long k = 1;
        cin >> a;
        int T[32];
        for(int i = 0; i < 32; i++)
        {
            if(a & 1<<i) T[31-i] = 0;
            else T[31-i] = 1;
        }
        long long result = 0;
        for(long long i = 0; i <= 31; i++) {
                result += T[31-i]*k;
                k *= 2;
        }
        cout << result << endl;
    }
    return 0;
}
