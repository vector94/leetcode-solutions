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

    bool hasPathSumHelper(TreeNode* root, int targetSum, int curSum){
        if (root -> left == NULL && root -> right == NULL){
            if (curSum + root -> val == targetSum)    return true;
            return false;
        }
        bool ret = false;
        if (root -> left){
            ret |= hasPathSumHelper(root -> left, targetSum, curSum + root -> val);
        }
        if (root -> right){
            ret |= hasPathSumHelper(root -> right, targetSum, curSum + root -> val);
        }
        return ret;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)   return false;
        return hasPathSumHelper(root, targetSum, 0);
    }
};