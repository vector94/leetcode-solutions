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

    void addOneRowHelper(TreeNode* root, int val, int depth, int curDepth){
        if (root == NULL)   return;
        if (curDepth == depth - 1){
            TreeNode* curLeft = root -> left;
            TreeNode* curRight = root -> right;

            TreeNode* newLeftNode = new TreeNode(val);
            TreeNode* newRightNode = new TreeNode(val);
            root -> left = newLeftNode;
            root -> left -> left = curLeft;
            root -> right = newRightNode;
            root -> right -> right = curRight;
            return;
        }
        addOneRowHelper(root -> left, val, depth, curDepth + 1);
        addOneRowHelper(root -> right, val, depth, curDepth + 1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1){
            TreeNode* cur = new TreeNode(val);
            cur -> left = root;
            return cur;
        }
        addOneRowHelper(root, val, depth, 1);
        return root;
    }
};