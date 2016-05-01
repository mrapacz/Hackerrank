#include <iostream>
#include <algorithm>

using namespace std;

struct node {
    int ind;
    int parent_ind;
};

ostream &operator<<(std::ostream &o, const node &a) {
    o << "index: " << a.ind << "\tparent ind: " << a.parent_ind << endl;
    return o;
}

node make_set(int id) {
    node x;
    x.ind = id;
    x.parent_ind = id;
    return x;
}

int find(int ind, node T[]) {
    cout << "im in " << ind << endl;
    cout << T[ind];
    if (T[ind].parent_ind != T[ind].ind)
        T[ind].parent_ind = find(T[ind].parent_ind, T);

    return T[ind].parent_ind;
}

void union_sets(int x, int y, node T[]) {
    int xParent = find(x, T);
    int yParent = find(y, T);
    if (xParent == yParent) return;
    T[xParent].parent_ind = yParent;
}

int main() {
    node T[3];
    for (int i = 0; i < 3; i++) {
        T[i] = make_set(i);
    }
    union_sets(0, 1, T);
    union_sets(1, 2, T);
    union_sets(2, 0, T);
    for (int i = 0; i < 3; i++) {
        cout << T[i].ind << " " << T[i].parent_ind << endl;
    }
    cout << "x" << endl;
    for (int i = 0; i < 3; i++) {
        cout << T[i].ind << " " << find(T[i].ind, T) << endl;
    }
    return 0;
}