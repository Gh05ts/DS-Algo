#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversalHelper(TreeNode* root, vector<int> &v) {
    if(!root) return {};
    v.push_back(root->val);
    preorderTraversalHelper(root->left, v);
    preorderTraversalHelper(root->right, v);
    return v;
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    return preorderTraversalHelper(root, ans);
}

vector<int> preorderTraversalIter(TreeNode* root) {
    stack<TreeNode*> st;
    vector<int> ans;
    st.push(root);
    while(!st.empty()) {
        auto node = st.top();
        st.pop();
        ans.push_back(node->val);
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
    }
    return ans;
}

vector<int> inorderTraversalHelp(TreeNode* root, vector<int> &v){
    if(!root) return {};
    inorderTraversal(root->left);
    v.push_back(root->val);
    inorderTraversal(root->right);
    return v;
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    return inorderTraversalHelp(root, ans);
}

vector<int> inorderTraversalIter(TreeNode* root) {
    stack<TreeNode*> st;
    vector<int> ans;
    auto curr = root;
    while(!st.empty() || curr) {
        while(curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop();
        ans.push_back(curr->val);
        curr = curr->right;
    }
}

vector<int> postorderTravesalHelp(TreeNode* root, vector<int> &v) {
    if(!root) return {};
    postorderTravesalHelp(root->left, v);
    postorderTravesalHelp(root->right, v);
    v.push_back(root->val);
    return v;
}

vector<int> postorderTravesal(TreeNode* root) {
    vector<int> ans;
    return postorderTravesalHelp(root, ans);
}

vector<int> postorderTravesalIter(TreeNode* root) {
    if(!root) return {};
    stack<TreeNode*> st;
    vector<int> ans;
    st.push(root);
    while(!st.empty()) {
        auto node = st.top(); st.pop();
        if(node->left) st.push(node->left);
        if(node->right) st.push(node->right);
        ans.push_back(node->val);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    if(!root) return {};
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        vector<int> level;
        int len = q.size();
        while(len--) {
            auto node = q.front(); q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}

vector<vector<int>> zigzag(TreeNode* root) {
    if(!root) return {};
    deque<TreeNode*> dq;
    vector<vector<int>> ans;
    dq.push_back(root);
    int flag = true;
    while(!dq.empty()) {
        vector<int> level;
        int len = dq.size();
        while(len--) {
            if(flag) {
                auto node = dq.front(); dq.pop_front();
                if(node->left) dq.push_back(node->left);
                if(node->right) dq.push_back(node->right);
                level.push_back(node->val);
            } else {
                auto node = dq.back(); dq.pop_back();
                if(node->right) dq.push_front(node->right);
                if(node->left) dq.push_front(node->left);
                level.push_back(node->val);
            }
        }
        flag = !flag;
        ans.push_back(level);
    }
    return ans;
}

int main() {

    return 0;
}