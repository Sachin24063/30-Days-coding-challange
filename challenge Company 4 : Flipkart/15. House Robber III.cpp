// In the Exponetial or 2^n time
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        int val = 0;
        if(root->left != NULL) val+= rob(root->left->left) + rob(root->left->right);
        if(root->right != NULL) val+= rob(root->right->left) + rob(root->right->right);
        return max(root->val+val, rob(root->left) + rob(root->right));
    }
};

// in optimised O(n) using Dynamic Programming
class Solution {
public:
map<TreeNode*, int> mp;
    int solve(TreeNode* root) {
        if(!root) return 0;
        if(mp.find(root)!=mp.end()) return mp[root];
        int ans_withroot_val = root->val;
        if(root->left) ans_withroot_val+= rob(root->left->left)+rob(root->left->right);
        if(root->right) ans_withroot_val+= rob(root->right->right)+rob(root->right->left);
        int ans_withoutroot_val = rob(root->left) + rob(root->right);
        int ans = max(ans_withroot_val, ans_withoutroot_val);
        mp[root] = ans;
        return ans;
    }
     int rob(TreeNode* root) {
         return solve(root);
     }
};
