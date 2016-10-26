#include <iostream>
using namespace std;

int main()
{
    int Z;
    cin >> Z;
    while(Z--)
    {
        long long result = 0;
        long long wrappers = 0;
        int n, c, m;
        cin >> n >> c >> m;
        wrappers += n/c;
        result += n/c;
        while(wrappers >= m)
        {
            int current = wrappers / m;
            result += current;
            wrappers = wrappers%m + current;
        }

        cout << result << endl;
    }

    return 0;
}
