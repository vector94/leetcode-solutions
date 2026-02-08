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
    bool solve(TreeNode *root, int targetSum, int curSum = 0){
        curSum += root -> val;
        if (root -> left == NULL && root -> right == NULL){
            return curSum == targetSum;
        }
        bool ret = false;
        if (root -> left){
            ret |= solve(root -> left, targetSum, curSum);
        }
        if (root -> right){
            ret |= solve(root -> right, targetSum, curSum);
        }
        return ret;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)   return 0;
        return solve(root, targetSum);
    }
};