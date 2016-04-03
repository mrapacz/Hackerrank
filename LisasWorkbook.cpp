//
// Created by maciej on 03.04.16.
//
#include <iostream>
#include <vector>

using namespace std;

int task(int last_task, int chap_start, int chap_end, int k) {
    int a = 1;
    int count = 0;
    for (int i = chap_start; i < chap_end; i++) {
        if (i >= a and i < a + k) count++;
        a += k;
    }
    if (chap_end >= a and chap_end <= last_task) count++;
    return count;
}

int main() {
    vector<int> T;
    int chapcount, k;
    cin >> chapcount >> k;

    //number of tasks in each chapter
    for (int i = 0; i < chapcount; i++) {
        int a;
        cin >> a;
        T.push_back(a);
    }

    //number of pages in each chapter
    vector<int> pageNum;
    for (int i = 0; i < chapcount; i++) {
        pageNum.push_back((T[i] + k - 1) / k);
    }


    int sum = 0;
    int page_count = 0;

    for (int i = 0; i < chapcount; i++) {
        int current = task(T[i], page_count + 1, page_count + A[i], k);
        sum += current;
        page_count += pageNum[i];
    }
    
    cout << sum << endl;
    return 0;
}