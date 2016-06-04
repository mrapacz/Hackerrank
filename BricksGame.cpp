#include <iostream>
#include <algorithm>

using namespace std;

long long int count_optimal(vector<int> &V, long long int optimal_scores[], int n, int index, long long int sum) {
    if (index == n) return 0;

    long long int result = 0;

    for (int taken_bricks = 1; taken_bricks <= 3; taken_bricks++) {
        if (taken_bricks + index <= n) {
            long long int local_sum = 0;
            for (int j = 0; j < taken_bricks; j++)
                local_sum += V[index + j];

            if (optimal_scores[index + taken_bricks] == -1)
                optimal_scores[index + taken_bricks] = count_optimal(V, optimal_scores, n, index + taken_bricks,
                                                                     sum - local_sum);

            long long int enemy_opt = optimal_scores[index + taken_bricks];
            result = max(result, sum - enemy_opt);
        }
    }
    return result;
}

int main() {
    int Z;
    cin >> Z;
    while (Z--) {
        int n;
        cin >> n;
        vector<int> V;
        long long int sum = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            sum += a;
            V.push_back(a);
        }
        long long int T[n + 1];
        for (int i = 0; i <= n; i++) T[i] = -1;
        cout << count_optimal(V, T, n, 0, sum) << endl;
    }
    return 0;
}