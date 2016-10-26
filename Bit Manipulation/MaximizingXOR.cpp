#include <iostream>
using namespace std;
void binToTable(int a, int T[32])
{
    int i = 0;
    while(i < 32)
    {
        T[i] = a%2;
        a = a/2;
        i++;
    }
}
long long dec(int A[32], int B[32])
{
    long long result = 0;
    long long scale = 1;
    for(int i = 0; i < 32; i++)
    {
        if(A[i] ^ B[i])
        {
            result += 1*scale;
        }
        scale = scale * 2;
    }
    return result;
}
int main()
{
    int l,r;
    cin >> l >> r;
    int A[32], B[32];
    long long max_v = 0;
    for(int i = l; i<=r; i++)
    {
        for(int j = i; j <= r; j++)
        {
            binToTable(i,A);
            binToTable(j,B);
            int current_v = dec(A,B);
            if(max_v < current_v) max_v = current_v;
        }
    }
    cout << max_v << endl;
    return 0;
}
