// C++ program to demonstrate 
// accessing of data members 

#include <bits/stdc++.h>
#include "data_structure/BinarySearchTree.h"
#include "data_structure/AVLTree.h"

int main() {
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
