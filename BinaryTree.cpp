#include "BinaryTree.h"

BinaryTree::BinaryTree(TreeNode* root) {
    this->root = root;
}

// bool BinaryTree::contains(int value) {

// }

void BinaryTree::print() {
    printHelper(root);
}

void BinaryTree::printHelper(TreeNode* node) {
    if (node != NULL) {
        cout<<node->data<<endl;
        printHelper(node->left);
        printHelper(node->right);
    }
}

void BinaryTree::printSideways() {

}