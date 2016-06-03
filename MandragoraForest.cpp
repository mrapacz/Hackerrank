#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long int get_score(int i, int n, long long int suffix[]) {
    return suffix[i] * (i + 1);
}

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        int n;
        cin >> n;
        vector<int> V;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            V.push_back(a);
        }
        sort(V.begin(), V.end());

        long long int suffix[n + 1];
        for (int i = 0; i < n + 1; i++) suffix[i] = 0;

        //fill prefix table
        long long int sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += V[i];
            suffix[i] = sum;
        }

        //get optimal score
        long long int best = 0;
        for (int i = 0; i < n; i++)
            best = max(best, get_score(i, n, suffix));

        cout << max(best, (long long int) (n + 1)) << endl;
    }
    return 0;
}