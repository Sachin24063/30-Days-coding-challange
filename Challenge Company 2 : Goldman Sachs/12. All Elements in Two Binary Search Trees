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
vector<int> final_list;
 void in_order_traversal(TreeNode *root){
        if(root){
            in_order_traversal(root->left);
            final_list.push_back(root->val);
            in_order_traversal(root->right);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        in_order_traversal(root1);
        in_order_traversal(root2);
        sort(final_list.begin(),final_list.end());
    return final_list;;
    }
};
