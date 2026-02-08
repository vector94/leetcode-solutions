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
    vector<int> v1, v2;
    void f1(TreeNode* root){
        if (root == NULL){
            v1.push_back(-1);
            return;
        }
        v1.push_back(root -> val);
        f1(root -> left);
        f1(root -> right);
    }
    void f2(TreeNode* root){
        if (root == NULL){
            v2.push_back(-1);
            return;
        }
        v2.push_back(root -> val);
        f2(root -> right);
        f2(root -> left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        f1(root);
        f2(root);
        return (v1 == v2);
    }
};