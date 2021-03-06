//
// Created by admin on 7/20/2018.
//
#include<vector>

#ifndef ACM_CPP_LIB_FENWICKTREE_H
#define ACM_CPP_LIB_FENWICKTREE_H
typedef std::vector<int> vi;

int LSOne(int i) {
    return (i & -i);
}

class FenwickTree {
private:
    vi ft;
public:
    FenwickTree(int n) {
        ft.assign(n + 1, 0);
    }
    int rsq(int b) {
        int sum = 0;
        for (; b; b -= LSOne(b))
            sum += ft[b];
        return sum;
    }

    int rsq(int a, int b) {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }

    void adjust(int k, int v) {
        for (; k < (int) ft.size(); k += LSOne(k))
            ft[k] += v;
    }
};


#endif //ACM_CPP_LIB_FENWICKTREE_H
