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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        pair<TreeNode*, int> result = findLCA(root);

        return result.first;
    }

    pair<TreeNode*, int> findLCA(TreeNode* curNode){
        if (!curNode){
            return {NULL, 0};
        }

        pair<TreeNode*, int> leftLCA = findLCA(curNode -> left);
        pair<TreeNode*, int> rightLCA = findLCA(curNode -> right);

        pair<TreeNode*, int> ret;
        if (leftLCA.second == rightLCA.second){
            ret = {curNode, leftLCA.second + 1};
        }
        else if (leftLCA.second > rightLCA.second){
            ret = {leftLCA.first , leftLCA.second + 1};
        }
        else{
            ret = {rightLCA.first, rightLCA.second + 1};
        }

        return ret;
    }
};