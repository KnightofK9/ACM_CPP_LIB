//
// Created by admin on 7/20/2018.
//
#include <vector>
#include <iostream>

#ifndef ACM_CPP_LIB_SEGMENTTREE_H
#define ACM_CPP_LIB_SEGMENTTREE_H
typedef std::vector<int> vi;

class SegmentTreeRMQ {
private:
    vi st, A;
    int n;

    int left(int p) { return p << 1; }

    int right(int p) { return (p << 1) + 1; }

    void build(int p, int L, int R) {
        if (L == R)
            st[p] = L;
        else {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }

    int rmq(int p, int L, int R, int i, int j) {
        if (i > R || j < L) return -1;
        if (L >= i && R <= j) return st[p];
        int p1 = rmq(left(p), L, (L + R) / 2, i, j);
        int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
        if (p1 == -1) return p2;
        if (p2 == -1) return p1;
        return (A[p1] <= A[p2]) ? p1 : p2;
    }

public:
    SegmentTreeRMQ(const vi &_A) {
        A = _A;
        n = (int) A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); } // overloading
};

class SegmentTreeRSQ {
private:
    vi st, A;
    int n;

    int left(int p) { return p << 1; }

    int right(int p) { return (p << 1) + 1; }

    void build(int p, int L, int R) {
        if (L == R) {
            st[p] = A[L];
        } else {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = p1 + p2;
        }
    }

    int rsq(int p, int L, int R, int i, int j) {
        if (i > R || j < L) return -1;
        if (L >= i && R <= j) return st[p];
        int p1 = rsq(left(p), L, (L + R) / 2, i, j);
        int p2 = rsq(right(p), (L + R) / 2 + 1, R, i, j);
        if (p1 == -1) return p2;
        if (p2 == -1) return p1;
        return p1 + p2;
    }

public:

    SegmentTreeRSQ(const vi &_A) {
        A = _A;
        n = (int) A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    int rsq(int i, int j) { return rsq(1, 0, n - 1, i, j); } // overloading
};

#endif //ACM_CPP_LIB_SEGMENTTREE_H
