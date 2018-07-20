// C++ program to demonstrate 
// accessing of data members 
#include <vector>
#include <bits/stdc++.h>
#include "data_structure/BinarySearchTree.h"
#include "data_structure/SegmentTree.h"

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
    testSegmentRSQ();
}