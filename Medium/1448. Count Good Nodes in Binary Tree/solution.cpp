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
    
    int goodNodeCount(TreeNode* curNode, int curMax){
        if (curNode == NULL){
            return 0;
        }
        return (curNode -> val >= curMax) + goodNodeCount(curNode -> left, max(curMax, curNode -> val)) + goodNodeCount(curNode -> right, max(curMax, curNode -> val));
    }
    
    int goodNodes(TreeNode* root) {
        return goodNodeCount(root, root -> val);
    }
};