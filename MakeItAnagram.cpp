#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;
    int T[26] = {0};
    for(int i = 0; i < a.size(); i++)
    {
        int current = a[i]-'a';
        T[current]++;
    }
    for(int i = 0; i < b.size(); i++)
    {
        int current = b[i]-'a';
        T[current]--;
    }
    int sum = 0;
    for(int i = 0; i < 26; i++)
        sum+= abs(T[i]);
    cout << sum << endl;
    return 0;
}
