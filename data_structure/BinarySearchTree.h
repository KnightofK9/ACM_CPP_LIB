//
// Created by admin on 7/18/2018.
//
#include <iostream>

#ifndef ACM_CPP_LIB_BST_H
#define ACM_CPP_LIB_BST_H

class Node {
public:
    int key;
    Node *left;
    Node *right;
    Node *parent;

    Node(int key, Node* parentNode = nullptr){
        this->key = key;
        this->left = this->right = nullptr;
        this->parent = parentNode;
    }
};

class BinarySearchTree {
public:
    Node *root;

    virtual ~BinarySearchTree() {
        travelRemove(this->root);
    }

    BinarySearchTree() {
        this->root = nullptr;
    }

    void insertKey(int key) {
        this->root = insertToNode(this->root, key);
    }

    bool isContainKey(int key){
        Node* node = searchNode(this->root, key);
        return node != nullptr;
    }

    void deleteKey(int key) {
        Node* node_to_delete = searchNode(this->root, key);
        if(node_to_delete == nullptr) return;
        deleteNode(node_to_delete);
    }

    void startTravel() {
        travel(this->root);
    }

private:
    void deleteNode(Node *node){
        Node *parent_node = node->parent;
        Node *left = node->left;
        Node *right = node->right;
        Node* replaced_node = nullptr;
        if(right == nullptr) {
            replaced_node = left;
        }
        else if (left == nullptr) {
            replaced_node = right;
        }
        if(left!=nullptr && right != nullptr)
        {
            replaced_node = findInOrderSuccessor(node->right);
            copyNodeIntoNode(replaced_node, node);
            deleteNode(replaced_node);
        }else
        {
            if(replaced_node != nullptr) replaced_node->parent = parent_node;
            if(parent_node->left == node) parent_node->left = replaced_node;
            else if(parent_node->right == node) parent_node->right = replaced_node;
            delete node;
        }


    }
    void copyNodeIntoNode(Node* from_node, Node* to_node){
        to_node->key = from_node->key;
        to_node->left = from_node->left;
        to_node->left->parent = to_node;

        to_node->right = from_node->right;
        to_node->right->parent = to_node;
    }

    Node *findInOrderSuccessor(Node *node){
        if(node == nullptr || node->left == nullptr) return node;
        return findInOrderSuccessor(node->left);
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

    void customFunction(int key) {
        std::cout << key << std::endl;
    }

    void travel(Node *node) {
        if (node != nullptr) {
            travel(node->left);
            customFunction(node->key);
            travel(node->right);
        }
    }

    void travelRemove(Node *node) {
        if (node != nullptr) {
            travelRemove(node->left);
            travelRemove(node->right);
            delete node;
        }
    }

    Node *insertToNode(Node *node, int key, Node* parentNode = nullptr) {
        if (node == nullptr) return new Node(key,parentNode);
        if (key < node->key) {
            node->left = insertToNode(node->left, key, node);
        } else if (key > node->key) {
            node->right = insertToNode(node->right, key, node);
        }
        return node;
    }
};


#endif //ACM_CPP_LIB_BST_H
