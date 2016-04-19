//
// Created by maciej on 19.04.16.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cost(int n) {
    int result = 0;
    result += n / 5;
    n = n % 5;
    result += n / 2;
    n = n % 2;
    result += n;

    return result;
}


int solution(int minimum, vector<int> V) {
    int result = 0;
    for (int i = 0; i < V.size(); i++) {
        result += cost(V[i] - minimum);
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
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            V.push_back(a);
        }
        int minimum = *min_element(V.begin(), V.end());

        int result = -1;
        for (int i = minimum - 4; i <= minimum; i++) {
            int current_result = solution(i, V);
            if (result == -1) result = current_result;
            else result = min(result, current_result);
        }
        cout << result << endl;
    }
    return 0;
}