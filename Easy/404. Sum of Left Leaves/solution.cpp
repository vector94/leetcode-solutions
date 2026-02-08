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
    
    int solve(int isLeft, TreeNode* node){
        if (!node -> left && !node -> right){
            if (isLeft) return node -> val;
            else        return 0;
        }
        int total = 0;
        if (node -> left){
            total = solve(1, node -> left);
        }
        if (node -> right){
            total += solve(0, node -> right);
        }
        return total;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL)   return 0;
        int result = solve(0, root);
        return result;
    }
};