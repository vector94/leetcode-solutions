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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        TreeNode *leftNode = root -> left;
        TreeNode *rightNode = root -> right;
        int l, r;
        l = r = 1;

        while (leftNode){
            leftNode = leftNode -> left;
            l++;
        }
        while (rightNode){
            rightNode = rightNode -> right;
            r++;
        }
        if (l == r) return (1 << l) - 1;
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};