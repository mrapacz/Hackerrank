#include <iostream>
#include <algorithm>

using namespace std;

struct node {
    int id;
    node *parent;
    int rank;
};

node *make_set(int id) {
    node *x = new node;
    x->id = id;
    x->parent = NULL;
    x->rank = 0;
    return x;
}

node *find(node *x) {
    if (x->parent == NULL) return x;
    else {
        x->parent = find(x->parent);
        return x->parent;
    }
}

void union_sets(node *x, node *y) {
    node *xRoot = find(x);
    node *yRoot = find(y);

    if (xRoot->rank > yRoot->rank)
        yRoot->parent = xRoot;
    if (xRoot->rank < yRoot->rank)
        xRoot->parent = yRoot;
    else if (xRoot != yRoot) {
        yRoot->parent = xRoot;
        xRoot->rank++;
    }
    return;
}

int main() {
    int a;
    node *x, *y;
    x = make_set(1);
    y = make_set(2);
    union_sets(x, y);
    cout << find(x)->id << endl;
    cout << find(y)->id << endl;
    return 0;
}