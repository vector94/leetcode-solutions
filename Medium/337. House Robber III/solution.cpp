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
    
    int robHelper(TreeNode* root, unordered_map<TreeNode*, int> &dp){
        if (root == NULL)   return 0;
        if (dp.find(root) != dp.end())  return dp[root];
        
        int result1 = robHelper(root -> left, dp) + robHelper(root -> right, dp);
        int result2 = root -> val;
        
        if (root -> left != NULL){
            result2 += robHelper(root -> left -> left, dp) + robHelper(root -> left -> right, dp);
        }
        
        if (root -> right != NULL){
            result2 += robHelper(root -> right -> left, dp) + robHelper(root -> right -> right, dp);
        }
        
        return dp[root] = max(result1, result2);
    }
    
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return robHelper(root, dp);
    }
};