// In n^2 time 
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
int ans = 0;
int count_node(TreeNode* root, int& cnt){
    if(root == NULL){ return 0;}
    cnt++;
    int left = count_node(root->left, cnt);
    int right = count_node(root->right, cnt);
    int val = root->val+left+right;
    return (root->val + left+ right);
}
void average(TreeNode* root){
    if(root == NULL){ return; }
    int count = 0;
    int avg = (count_node(root,count))/count;
       if(avg == root->val){ans++;}
        average(root->left);
        average(root->right);
}
    int averageOfSubtree(TreeNode* root) {
        average(root);
        return ans;
    }
};

// In O(n) time
class Solution {
public:
//Optimized Version In O(n)
    int ans = 0;
    pair<int, int> sol(TreeNode* root){
        if(root == NULL) return {0,0};

        auto left = sol(root->left);
        int left_sum = left.first;
        int left_cnt = left.second;

        auto right = sol(root->right);
        int right_sum = right.first;
        int right_cnt = right.second;

        int sum = root->val + left_sum + right_sum;
        int count = left_cnt + right_cnt + 1;

        if(root->val == sum/count) ans++;
        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        sol(root);
        return ans;
    }
};
