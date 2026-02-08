/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* resultNode;
    void getTarget(TreeNode *original, TreeNode* cloned, TreeNode* target){
        if (original == NULL) return;
        if (original == target){
            resultNode = cloned;
            return;
        }
        getTarget(original -> left, cloned -> left, target);
        getTarget(original -> right, cloned -> right, target);
        return;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        getTarget(original, cloned, target);
        
        return resultNode;
    }
};