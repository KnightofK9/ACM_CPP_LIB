//
// Created by admin on 7/18/2018.
//
#include <iostream>
#include <algorithm>
#include <string>

#ifndef ACM_CPP_LIB_BST_H
#define ACM_CPP_LIB_BST_H


class AVLTree {


    class Node {
    public:
        int key;
        Node *left;
        Node *right;
        int height;

        Node(int key) {
            this->key = key;
            this->left = this->right = nullptr;
            this->height = 1;
        }

    };

public:
    Node *root;

    virtual ~AVLTree() {
        travelDelete(this->root);
    }

    AVLTree() {
        this->root = nullptr;
    }

    void insertKey(int key) {
        this->root = insert(this->root, key);
    }

    bool isContainKey(int key) {
        return searchNode(this->root, key) != nullptr;
    }

    void deleteKey(int key) {
        deleteNode(this->root, key);
    }

    void startTravel() {
//        travel(this->root);
    }

    int getHeight() {
        return height(this->root);
    }

    void printTree() {
        printNode(this->root,0);
    }

private:
    Node *searchNode(Node *node, int key) {
        if (node == nullptr) {
            return nullptr;
        }
        if(node->key == key){
            return node;
        }
        if(key > node->key){
            return searchNode(node->right, key);
        }else{
            return searchNode(node->left, key);
        }
    }
    void printNode(Node* node, int tab){
        if(node == nullptr) return;
        printNode(node->right, tab + 1);
        std::cout<<getTabS(tab) << node->key<<std::endl;
        printNode(node->left, tab + 1);

    }
    std::string getTabS(int tab){
        std::string tab_s;
        for(int i = 0; i < tab; i++){
            tab_s += "\t";
        }
        return tab_s;
    }
    int height(Node* node){
        if(node == nullptr) return 0;
        return node->height;
    }
    Node* rightRotate(Node* node){
        Node* T1 = node->left;
        Node* T2 = T1->right;
        node->left = T2;
        T1->right = node;

        node->height = 1 + std::max(height(node->left), height(node->right));
        T1->height = 1 + std::max(height(T1->left), height(T1->right));
        return T1;
    }
    Node* leftRotate(Node* node){

        Node* T1 = node->right;
        Node* T2 = T1->left;
        node->right = T2;
        T1->left = node;

        node->height = 1 + std::max(height(node->left), height(node->right));
        T1->height = 1 + std::max(height(T1->left), height(T1->right));
        return T1;
    }
    Node* insert(Node* node, int key){
        if(node == nullptr) return new Node(key);
        if(key < node->key) node->left = insert(node->left, key);
        else if(key > node->key) node->right = insert(node->right, key);
        else return node;

        node->height = 1 + std::max(height(node->left), height(node->right));
        int balance = getBalance(node);
        if(balance > 1 && key < node->left->key){
            return rightRotate(node);
        }
        if(balance > 1 && key > node->left->key){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if(balance < -1 && key > node->right->key){
            return leftRotate(node);
        }
        if(balance < -1 && key < node->right->key){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    Node* deleteNode(Node* node, int key){
        if(node == nullptr) return nullptr;
        if(key < node->key) node->left = deleteNode(node->left, key);
        else if(key > node->key) node->right = deleteNode(node->right, key);
        else {
            if(node->left == nullptr || node->right==nullptr){
                Node* temp = node->left != nullptr ? node->left : node->right;
                if(temp == nullptr){
                    temp = node;
                    node = nullptr;
                }else
                    *node = *temp;
                delete temp;
            }else{
                Node* t = findInOrderSuccessor(node->right);
                node->key = t->key;
                node->right = deleteNode(node->right, node->key);
            }
        }
        if(node == nullptr) return node;
        node->height = 1 + std::max(height(node->left), height(node->right));
        int balance = getBalance(node);
        if(balance > 1 && key < node->left->key){
            return rightRotate(node);
        }
        if(balance > 1 && key > node->left->key){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if(balance < -1 && key > node->right->key){
            return leftRotate(node);
        }
        if(balance < -1 && key < node->right->key){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;

    }
    int getBalance(Node* node){
        return height(node->left) - height(node->right);
    }

    Node *findInOrderSuccessor(Node *node){
        if(node == nullptr || node->left == nullptr) return node;
        return findInOrderSuccessor(node->left);
    }

    void travelDelete(Node* node){
        if(node==nullptr) return;
        travelDelete(node->left);
        travelDelete(node->right);
        delete node;
    }
};



class BinarySearchTree {


    class Node {
    public:
        int key;
        Node *left;
        Node *right;
        int height;

        Node(int key) {
            this->key = key;
            this->left = this->right = nullptr;
            this->height = 1;
        }

    };

public:
    Node *root;

    virtual ~BinarySearchTree() {
        travelDelete(this->root);
    }

    BinarySearchTree() {
        this->root = nullptr;
    }

    void insertKey(int key) {
        this->root = insert(this->root, key);
    }

    bool isContainKey(int key) {
        return searchNode(this->root, key) != nullptr;
    }

    void deleteKey(int key) {
        deleteNode(this->root, key);
    }

    void startTravel() {
//        travel(this->root);
    }

    int getHeight() {
        return height(this->root);
    }

    void printTree() {
        printNode(this->root,0);
    }

private:
    void travelDelete(Node* node){
        if(node==nullptr) return;
        travelDelete(node->left);
        travelDelete(node->right);
        delete node;
    }
    Node *searchNode(Node *node, int key) {
        if (node == nullptr) {
            return nullptr;
        }
        if(node->key == key){
            return node;
        }
        if(key > node->key){
            return searchNode(node->right, key);
        }else{
            return searchNode(node->left, key);
        }
    }
    void printNode(Node* node, int tab){
        if(node == nullptr) return;
        printNode(node->right, tab + 1);
        std::cout<<getTabS(tab) << node->key<<std::endl;
        printNode(node->left, tab + 1);

    }
    std::string getTabS(int tab){
        std::string tab_s;
        for(int i = 0; i < tab; i++){
            tab_s += "\t";
        }
        return tab_s;
    }
    int height(Node* node){
        if(node == nullptr) return 0;
        return node->height;
    }
    Node* insert(Node* node, int key){
        if(node == nullptr) return new Node(key);
        if(key < node->key) node->left = insert(node->left, key);
        else if(key > node->key) node->right = insert(node->right, key);
        else return node;
        node->height = 1 + std::max(height(node->left), height(node->right));
        return node;
    }
    Node* deleteNode(Node* node, int key){
        if(node == nullptr) return nullptr;
        if(key < node->key) node->left = deleteNode(node->left, key);
        else if(key > node->key) node->right = deleteNode(node->right, key);
        else {
            if(node->left == nullptr || node->right==nullptr){
                Node* temp = node->left != nullptr ? node->left : node->right;
                if(temp == nullptr){
                    temp = node;
                    node = nullptr;
                }else
                    *node = *temp;
                delete temp;
            }else{
                Node* t = findInOrderSuccessor(node->right);
                node->key = t->key;
                node->right = deleteNode(node->right, node->key);
            }
        }
        if(node == nullptr) return node;
        node->height = 1 + std::max(height(node->left), height(node->right));
        return node;

    }
    int getBalance(Node* node){
        return height(node->left) - height(node->right);
    }

    Node *findInOrderSuccessor(Node *node){
        if(node == nullptr || node->left == nullptr) return node;
        return findInOrderSuccessor(node->left);
    }
};


#endif //ACM_CPP_LIB_BST_H
