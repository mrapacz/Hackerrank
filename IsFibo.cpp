#include <iostream>
using namespace std;
const int N = 11;
void sum(int A[N], int B[N], int T[N])
{
    for(int i = 0; i < N; i++) T[i] = 0;
    int p = 0;
    for(int i = N-1; i >= 0; i--)
    {
        T[i] = A[i] + B[i] + p;
        p = T[i] / 10;
        T[i] = T[i] % 10;
    }
}
bool equal (int T[N], string s)
{
    int j = N-1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if(s[i]-'0' != T[j]) return false;
        j--;
    }
    return true;
}
int rozm(int T[N])
{
    int i = 0;
    while(T[i] == 0 && i < N) i++;
    return N-i;
}
void print(int T[N])
{
    int i = 0;
    while(T[i] == 0 && i < N) i++;

    while(i < N)
    {
        cout << T[i];
        i++;
    }
    cout << endl;
}
int main()
{
    int Z;
    cin >> Z;
    while(Z--)
    {
        int A[N] = {0}, B[N] = {0}, T[N] = {0}, zero[N] = {0};
        A[N-1] = 0;
        B[N-1] = 1;
        T[N-1] = 0;
        string n;
        cin >> n;
        bool is_fibo = false;
        while(rozm(T) <= n.size())
        {
            sum(B,zero,A);
            sum(T,zero,B);
            sum(A,B,T);
            if(equal(T,n)) is_fibo = true;
        }
        if(is_fibo) cout << "IsFibo" << endl;
        else cout << "IsNotFibo" << endl;
    }
}
