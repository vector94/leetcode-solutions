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
    
    int helper(TreeNode* root, int curNum){
        if (root == NULL)   return 0;
        curNum = curNum * 2 + root -> val;
        if (root -> left == NULL && root -> right == NULL){
            return curNum;
        }
        return helper(root -> left, curNum) + helper(root -> right, curNum);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        return helper(root, 0);
    }
};