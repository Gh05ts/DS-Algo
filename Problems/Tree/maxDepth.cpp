#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void maxDepthHelp(TreeNode* root, int depth, int &ans) {
    if(!root) return;
    if(!root->left && !root->right) ans = max(depth, ans);
    maxDepthHelp(root->left, depth + 1, ans);
    maxDepthHelp(root->right, depth + 1, ans);
}

int maxDepth(TreeNode* root) {
    int ans(0);
    maxDepthHelp(root, 1, ans);
    return ans;
}

int maxDepthBU(TreeNode* root) {
    if(!root) return 0;
    int left = maxDepthBU(root->left);
    int right = maxDepthBU(root->right);
    return max(left, right) + 1;

}

int main() {

    return 0;
}