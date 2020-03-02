#include <vector>
#include <iostream>

using std::vector, std::cout;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* helper(int preSt, int preEnd, int postSt, int postEnd, vector<int> &pre, vector<int>& post) {
    if(preSt > preEnd || postSt > postEnd) return nullptr;

    TreeNode *root = new TreeNode(pre[preSt]);

    int pivot1;
    int pivot2;

    // root->left = helper(x, xx, xxx, xxxx, pre, post);
    // root->right = helper(x, xx, xxx, xxxx, pre, post);

    return root;
}

TreeNode* makeTree(vector<int>& pre, vector<int>& post) {
    return helper(0, pre.size() - 1, 0, post.size() - 1, pre, post);
}

int main() {
    vector<int> a{5, 1, 0, 3, 2, 4, 6, 8, 7, 10, 9};
    vector<int> b{0, 2, 4, 3, 1, 7, 10, 8, 9, 6, 5};
    TreeNode *root = makeTree(a, b);
    return 0;
}