// C++ program to demonstrate 
// accessing of data members 

#include <bits/stdc++.h>
#include "data_structure/BinarySearchTree.h"

int main() {
    BinarySearchTree tree;
    tree.insertKey(50);
    tree.insertKey(30);
    tree.insertKey(20);
    tree.insertKey(40);
    tree.insertKey(70);
    tree.insertKey(60);
    tree.insertKey(80);

    tree.startTravel();
    bool is_contain = tree.isContainKey(40);
    std::cout<<is_contain<<std::endl;

    tree.deleteKey(40);
    is_contain = tree.isContainKey(40);
    std::cout<<is_contain<<std::endl;

    tree.startTravel();
    return 0;
}
