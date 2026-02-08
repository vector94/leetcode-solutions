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
    
    pair<int, int> maxAncestorDiffHelper(TreeNode* curNode, int &result){
        if (curNode -> left == NULL && curNode -> right == NULL)    return {curNode -> val, curNode -> val};
        
        pair<int, int> piiLeft, piiRight;
        if (curNode -> right == NULL){
            piiLeft = maxAncestorDiffHelper(curNode -> left, result);
            piiRight = {curNode -> val, curNode -> val};
        }
        else if (curNode -> left == NULL){
            piiLeft = {curNode -> val, curNode -> val};
            piiRight = maxAncestorDiffHelper(curNode -> right, result);
        }
        else{
            piiLeft = maxAncestorDiffHelper(curNode -> left, result);
            piiRight = maxAncestorDiffHelper(curNode -> right, result);
        }
        
        result = max({result, max(piiLeft.first, piiRight.first) - curNode -> val, curNode -> val - min(piiLeft.second, piiRight.second)});
        
        pair<int, int> piiRet = {max({piiLeft.first, piiRight.first, curNode -> val}), min({piiLeft.second, piiRight.second, curNode -> val})};
        
        return piiRet;
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int result = 0;
        
        maxAncestorDiffHelper(root, result);
        
        return result;
    }
};