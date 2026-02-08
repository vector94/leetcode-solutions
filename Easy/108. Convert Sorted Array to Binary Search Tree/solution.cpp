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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL)
            root = new TreeNode(val);
        else if (root->val < val) {
            root->right = insertIntoBST(root->right, val);
        }
        else if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
    TreeNode* solve(TreeNode* root, int l, int r, vector<int>& nums){
        if (l == r){
            root = insertIntoBST(root, nums[l]);
        }
        else if (l + 1 == r){
            root = insertIntoBST(root, nums[l]);
            root = insertIntoBST(root, nums[l + 1]);
        }
        else{
            int mid = l + (r - l) / 2;
            root = insertIntoBST(root, nums[mid]);
            root = solve(root, l, mid - 1, nums);
            root = solve(root, mid + 1, r, nums);
        }
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = NULL;
        if (nums.empty()){
            return root;
        }
        return solve(root, 0, nums.size() - 1, nums);
    }
};