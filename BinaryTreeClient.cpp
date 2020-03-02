#include "BinaryTree.h"

int main() {
    
    TreeNode* node = new TreeNode(4);
    node->left = new TreeNode(5);
    node->left->left = new TreeNode(6);
    node->left->right = new TreeNode(8);
    node->right = new TreeNode(7);
    node->right->left = new TreeNode(78);
    node->right->right = new TreeNode(9);

    BinaryTree tree(node);
    tree.print();
}