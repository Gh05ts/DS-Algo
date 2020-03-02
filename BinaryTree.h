#ifndef BinaryTree_h
#define BinaryTree_h

#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data, TreeNode* left = NULL, TreeNode* right = NULL) {
        this->data = data;
        this->left = left;
        this->right = right;
    }

    bool isLeaf() {
        return left == NULL && right == NULL;
    }
};

class BinaryTree {
public:
    BinaryTree(TreeNode*);
    void print();
    // bool contains(int);
    void printSideways();
private:
    TreeNode* root;
    void printHelper(TreeNode*);
};

#endif