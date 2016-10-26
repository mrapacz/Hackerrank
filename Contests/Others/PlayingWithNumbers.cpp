#include <iostream>
#include <algorithm>

using namespace std;

void fill_prefix_table(vector<int> V, vector<int> &prefix) {
    int sum = 0;
    prefix.push_back(0);
    for (int i = 0; i < V.size(); i++) {
        sum += abs(V[i]);
        prefix.push_back(sum);
    }
}

int get_sum(int a, int b, vector<int> V, vector<int> prefix) {
    if (b < a) return 0;
    return prefix[b + 1] - prefix[a];
}

int get_count(int a, int b) {
    if (b < a) return 0;
    else return b - a + 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> V;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        V.push_back(a);
    }
    sort(V.begin(), V.end());

    vector<int> prefix;
    fill_prefix_table(V, prefix);


    int querry_count, q;
    cin >> querry_count;
    long long int current_factor = 0;
    int mid = lower_bound(V.begin(), V.end(), 0) - V.begin();
    for (int i = 0; i < querry_count; i++) {
        cin >> q;

        current_factor += q;
        long long int current_result = prefix[n]; //(0, pivot-1), (pivot, mid -1), (mid, V.size()-1)

        if (current_factor != 0) {
            int pivot = lower_bound(V.begin(), V.end(), -current_factor) - V.begin();
            current_result += (get_count(mid, n - 1) - get_count(0, pivot - 1)) * current_factor;
            current_result += -2 * get_sum(pivot, mid - 1, V, prefix);
            current_result += get_count(pivot, mid - 1) * current_factor;

        }
        cout << current_result << endl;
    }
    return 0;
}