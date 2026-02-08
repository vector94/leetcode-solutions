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
    bool flag = 1;
    int solve(TreeNode* root){
        if (root == NULL){
            return 0;
        }
        int l = 1 + solve(root -> left);
        int r = 1 + solve(root -> right);
        if (abs(l - r) > 1){
            flag = 0;
        }
        return max(l, r);
    }
public:
    bool isBalanced(TreeNode* root) {
        solve(root);
        return flag;
    }
};