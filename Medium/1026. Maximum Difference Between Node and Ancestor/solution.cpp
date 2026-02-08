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
    int maxAncestorDiff(TreeNode* root) {
        if (root == NULL)   return 0;
        return maxAncestorDiffHelper(root, root -> val, root -> val);
    }

    int maxAncestorDiffHelper(TreeNode* root, int curMin, int curMax){
        if (root == NULL)   return curMax - curMin;
        return max(maxAncestorDiffHelper(root -> left, min(curMin, root -> val), max(curMax, root -> val)),
                    maxAncestorDiffHelper(root -> right, min(curMin, root -> val), max(curMax, root -> val)));
    }
};