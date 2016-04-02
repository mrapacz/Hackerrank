#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    vector<int> row;
    vector<int> column;
    vector<int> newrow;
    vector<int> newcolumn;
    
    int x = 0;
    
    if (a[0] == b[0]) x = 1;
    
    row.push_back(x);
    column.push_back(x);

    for (int i = 1; i < b.size(); i++) {
        if (a[0] == b[i])
            row.push_back(1);
        else
            row.push_back(row[i - 1]);
    }


    for (int j = 1; j < a.size(); j++) {
        if (a[j] == b[0])
            column.push_back(1);
        else
            column.push_back(column[j - 1]);
    }
    newrow = row;
    newcolumn = column;


    for (int i = 1; i < b.size(); i++) {
        newcolumn[0] = row[i];
        for (int j = 1; j < a.size(); j++) {
            if (a[j] == b[i])
                newcolumn[j] = column[j - 1] + 1;
            else
                newcolumn[j] = max(newcolumn[j - 1], column[j]);
        }
        column = newcolumn;
    }
    cout << column[a.size() - 1] << endl;
    return 0;
}
