// C++ program to demonstrate 
// accessing of data members 
#include <vector>
#include <bits/stdc++.h>
#include "data_structure/BinarySearchTree.h"
#include "data_structure/SegmentTree.h"
#include "data_structure/FenwickTree.h"

typedef std::vector<int> vi;



int testSegmentRMQ() {
    int arr[] = { 18, 17, 13, 19, 15, 11, 20 };
    vi A(arr, arr + 7);
    SegmentTreeRMQ st(A);
    std::cout<<"RMQ(1, 3) = "<< st.rmq(1, 3)<<std::endl;
    std::cout<<"RMQ(4, 6) = "<< st.rmq(4, 6)<<std::endl;
}
int testSegmentRSQ() {
    int arr[] = { 18, 17, 13, 19, 15, 11, 20 };
    vi A(arr, arr + 7);
    SegmentTreeRSQ st(A);
    std::cout<<"RMQ(1, 3) = "<< st.rsq(1, 3)<<std::endl;
    std::cout<<"RMQ(4, 6) = "<< st.rsq(4, 6)<<std::endl;
}
int LSO(int i){
    return (i & (-i));
}
void testFenwick(){
    int f[] = { 2,4,5,5,6,6,6,7,7,8,9 }; // m = 11 scores
    FenwickTree ft(10); // declare a Fenwick Tree for range [1..10]
// insert these scores manually one by one into an empty Fenwick Tree
    for (int i = 0; i < 11; i++) ft.adjust(f[i], 1); // this is O(k log n)
    printf("%d\n", ft.rsq(1, 1)); // 0 => ft[1] = 0
    printf("%d\n", ft.rsq(1, 2)); // 1 => ft[2] = 1
    printf("%d\n", ft.rsq(1, 6)); // 7 => ft[6] + ft[4] = 5 + 2 = 7
    printf("%d\n", ft.rsq(1, 10)); // 11 => ft[10] + ft[8] = 1 + 10 = 11
    printf("%d\n", ft.rsq(3, 6)); // 6 => rsq(1, 6) - rsq(1, 2) = 7 - 1
    ft.adjust(5, 2); // update demo
    printf("%d\n", ft.rsq(1, 10)); // now 13
}
void testLSO(){
    std::cout<<LSO(90)<<std::endl;
}

int testBST(){
    //    BinarySearchTree tree;
    AVLTree tree;
    tree.insertKey(10);
    std::cout<<"----"<<std::endl;
    tree.printTree();
    tree.insertKey(20);
    std::cout<<"----"<<std::endl;
    tree.printTree();
    tree.insertKey(30);
    std::cout<<"----"<<std::endl;
    tree.printTree();
    tree.insertKey(40);
    std::cout<<"----"<<std::endl;
    tree.printTree();
    tree.insertKey(50);
    std::cout<<"----"<<std::endl;
    tree.printTree();
    tree.insertKey(60);
    std::cout<<"----"<<std::endl;
    tree.printTree();
    tree.insertKey(70);
    std::cout<<"----"<<std::endl;
    tree.printTree();
    tree.insertKey(80);
    std::cout<<"----"<<std::endl;
    tree.printTree();
    tree.insertKey(90);
    std::cout<<"----"<<std::endl;
    tree.printTree();
    tree.insertKey(100);
    std::cout<<"----"<<std::endl;
    tree.printTree();

    std::cout<<"Height: "<<tree.getHeight()<<std::endl;

    int keyToRemove = 40;

    bool is_contain = tree.isContainKey(keyToRemove);
    std::cout<<"Is contain key "<<keyToRemove<<":"<<is_contain<<std::endl;

    tree.deleteKey(keyToRemove);
    is_contain = tree.isContainKey(keyToRemove);
    std::cout<<"Is contain key "<<keyToRemove<<":"<<is_contain<<std::endl;

    tree.printTree();

    std::cout<<"Height: "<<tree.getHeight()<<std::endl;
    return 0;
}

int main() {
    testLSO();
}