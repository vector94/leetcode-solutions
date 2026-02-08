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
    
    bool validate(TreeNode* root, long left, long right){
        if (root == NULL)   return true;
        
        if (root -> val > left && root -> val < right){
            return validate(root -> left, left, root -> val)
                && validate(root -> right, root -> val, right);
        }
        else{
            return false;
        }
    }
    
    bool isValidBST(TreeNode* root) {
        long inf = 1e10;
        return validate(root, -inf, inf);
    }
};