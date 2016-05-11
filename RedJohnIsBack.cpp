#include <iostream>
#include <algorithm>

using namespace std;

int puzzle(int &n, int a, int b, int c, int d){
    int result = 0;
    if(a == b == c == d == n) return 1;
    if(a < n and b < n and c < n and d < n) result += puzzle(n, a+1, b+1, c+1, d+1);
    if(a + 4 <= n) result += puzzle(n, a+4, )

}

int main() {
    int n;
    cin >> n;

    return 0;
}